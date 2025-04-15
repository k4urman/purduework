/*
 * Homework 11
 * Maninder (Kaurman) Kaur
 * CS 240, Spring 2025
 * Purdue University
 */

/* Write your code here */
#include <assert.h>
#include <malloc.h>
#include <string.h>
#include "hw11.h"

// Helper function to duplicate a string
static char *strdup(const char *src) {
    assert(src != NULL);
    char *dst = malloc(strlen(src) + 1);
    assert(dst != NULL);
    strcpy(dst, src);
    return dst;
}

// Helper function to count sites in a ring's CDLL
static int count_sites(site_t *site_list) {
    if (site_list == NULL) return 0;
    int count = 0;
    site_t *current = site_list;
    do {
        count++;
        current = current->next_site;
    } while (current != site_list);
    return count;
}

// Helper function to find the head of a CDLL based on shortest name length or lexicographical order
static site_t *find_cdll_head(site_t *site) {
    if (site == NULL) return NULL;
    site_t *current = site;
    site_t *head = site;
    do {
        if (strlen(current->site_name) < strlen(head->site_name) ||
            (strlen(current->site_name) == strlen(head->site_name) &&
             strcmp(current->site_name, head->site_name) < 0)) {
            head = current;
        }
        current = current->next_site;
    } while (current != site);
    return head;
}

// Create a new ring
ring_t *create_ring(char *ring_name) {
    assert(ring_name != NULL);
    ring_t *new_ring = malloc(sizeof(ring_t));
    assert(new_ring != NULL);
    new_ring->ring_name = strdup(ring_name);
    new_ring->site_list = NULL;
    new_ring->left = NULL;
    new_ring->right = NULL;
    return new_ring;
}

// Add a site to a ring's CDLL
void add_site_to_ring(ring_t *ring, char *site_name) {
    assert(ring != NULL && site_name != NULL);
    site_t *new_site = malloc(sizeof(site_t));
    assert(new_site != NULL);
    new_site->site_name = strdup(site_name);

    if (ring->site_list == NULL) {
        new_site->next_site = new_site;
        new_site->prev_site = new_site;
        ring->site_list = new_site;
        return;
    }

    // Find insertion point
    site_t *current = ring->site_list;
    site_t *insert_pos = NULL;
    do {
        int curr_len = strlen(current->site_name);
        int new_len = strlen(new_site->site_name);
        if (new_len < curr_len ||
            (new_len == curr_len && strcmp(new_site->site_name, current->site_name) < 0)) {
            insert_pos = current;
            break;
        }
        current = current->next_site;
    } while (current != ring->site_list);

    // If no insert_pos found, insert before site_list (as it has longer name or lexicographically later)
    if (insert_pos == NULL) {
        insert_pos = ring->site_list;
    }

    // Insert new_site before insert_pos
    new_site->next_site = insert_pos;
    new_site->prev_site = insert_pos->prev_site;
    insert_pos->prev_site->next_site = new_site;
    insert_pos->prev_site = new_site;

    // Update site_list to head
    ring->site_list = find_cdll_head(new_site);
}

// Insert a ring into the BST
void insert_ring(ring_t **root, ring_t *new_ring) {
    assert(root != NULL && new_ring != NULL);
    if (*root == NULL) {
        *root = new_ring;
        return;
    }
    if (strcmp(new_ring->ring_name, (*root)->ring_name) < 0) {
        insert_ring(&(*root)->left, new_ring);
    } else {
        insert_ring(&(*root)->right, new_ring);
    }
}

// Purge rings with fewer than min_sites
int purge_small_rings(ring_t **root, int min_sites) {
    assert(root != NULL && min_sites >= 0);
    if (*root == NULL) return 0;

    int left_purged = purge_small_rings(&(*root)->left, min_sites);
    int right_purged = purge_small_rings(&(*root)->right, min_sites);

    if (count_sites((*root)->site_list) < min_sites) {
        ring_t *to_delete = *root;

        if (to_delete->site_list != NULL) {
            site_t *current = to_delete->site_list;
            site_t *start = current;
            do {
                site_t *next = current->next_site;
                free(current->site_name);
                free(current);
                current = next;
            } while (current != start);
        }

        if (to_delete->left == NULL && to_delete->right == NULL) {
            *root = NULL;
        } else if (to_delete->left == NULL) {
            *root = to_delete->right;
        } else if (to_delete->right == NULL) {
            *root = to_delete->left;
        } else {
            ring_t **successor = &to_delete->right;
            while ((*successor)->left != NULL) {
                successor = &(*successor)->left;
            }
            ring_t *succ = *successor;
            *successor = succ->right;
            succ->left = to_delete->left;
            succ->right = to_delete->right;
            *root = succ;
        }

        free(to_delete->ring_name);
        free(to_delete);
        return left_purged + right_purged + 1;
    }

    return left_purged + right_purged;
}

int delete_dead_links(ring_t *root, char *flag_word) {
    // Assert that inputs are not NULL
    assert(root != NULL);
    assert(flag_word != NULL);

    int total_deleted = 0;

    // Recursively process left and right subtrees if they exist
    if (root->left != NULL) {
        total_deleted += delete_dead_links(root->left, flag_word);
    }
    if (root->right != NULL) {
        total_deleted += delete_dead_links(root->right, flag_word);
    }

    // Process the current ring's site list
    site_t *current = root->site_list;
    if (current == NULL) {
        return total_deleted;
    }

    site_t *head = current;
    site_t *to_delete = NULL;
    int sites_processed = 0;
    int sites_deleted = 0;

    // Traverse the CDLL to delete sites containing flag_word
    do {
        if (strstr(current->site_name, flag_word) != NULL) {
            to_delete = current;
            site_t *prev = current->prev_site;
            site_t *next = current->next_site;

            prev->next_site = next;
            next->prev_site = prev;

            // If deleting the head, update head before moving
            if (to_delete == head) {
                head = (next != to_delete) ? next : NULL;
            }

            // Move current to next before freeing
            current = next;

            free(to_delete->site_name);
            free(to_delete);
            sites_deleted++;

            // If all sites are deleted, break out of the loop
            if (head == NULL) {
                break;
            }
        } else {
            current = current->next_site;
        }
        sites_processed++;
    } while (current != head && sites_processed < 1000); // Safety limit

    // Update the ring's site_list to the new head or NULL
    if (head == NULL) {
        root->site_list = NULL;
    } else {
        // Find the new head according to the specified order
        site_t *new_head = head;
        int min_len = strlen(new_head->site_name);
        site_t *temp = new_head->next_site;

        while (temp != head) {
            int curr_len = strlen(temp->site_name);
            if (curr_len < min_len || (curr_len == min_len && strcmp(temp->site_name, new_head->site_name) < 0)) {
                new_head = temp;
                min_len = curr_len;
            }
            temp = temp->next_site;
        }
        root->site_list = new_head;
    }

    total_deleted += sites_deleted;
    return total_deleted;
}




int total_surf_chain_length(ring_t *root) {
    // Handle empty BST case first
    if (root == NULL) {
        return 0;
    }
    // Assertion for non-NULL root (as per problem statement)
    assert(root != NULL);
    return count_sites(root->site_list) +
           total_surf_chain_length(root->left) +
           total_surf_chain_length(root->right);
}





int scavenge_neighboring_rings(ring_t *root, int min_sites) {
    assert(root != NULL && min_sites >= 0);
    int scavenged = 0;
    int current_count = count_sites(root->site_list);

    if (current_count < min_sites) {
        ring_t *child = NULL;
        int left_count = (root->left) ? count_sites(root->left->site_list) : 0;
        int right_count = (root->right) ? count_sites(root->right->site_list) : 0;
        int needed = min_sites - current_count;

        // Choose child with sufficient sites
        if (left_count >= right_count) {
            if (root->left && (left_count - needed) >= min_sites) child = root->left;
        } else {
            if (root->right && (right_count - needed) >= min_sites) child = root->right;
        }

        if (child) {
            site_t **to_move = malloc(needed * sizeof(site_t *));
            int move_count = 0;

            for (int i = 0; i < needed; i++) {
                site_t *min_site = child->site_list;
                site_t *current = child->site_list;
                if (!current) break;

                do { // Find smallest site
                    if (strlen(current->site_name) < strlen(min_site->site_name) ||
                        (strlen(current->site_name) == strlen(min_site->site_name) &&
                        strcmp(current->site_name, min_site->site_name) < 0)) {
                        min_site = current;
                    }
                    current = current->next_site;
                } while (current != child->site_list);

                // Remove min_site from child
                min_site->prev_site->next_site = min_site->next_site;
                min_site->next_site->prev_site = min_site->prev_site;
                if (min_site == child->site_list) {
                    child->site_list = (min_site->next_site != min_site) ? min_site->next_site : NULL;
                }
                to_move[move_count++] = min_site;
            }

            // Transfer sites
            for (int i = 0; i < move_count; i++) {
                add_site_to_ring(root, to_move[i]->site_name);
                free(to_move[i]->site_name);
                free(to_move[i]);
                scavenged++;
            }
            free(to_move);

            if (child->site_list) child->site_list = find_cdll_head(child->site_list);
        }
    }

    // Recursive calls with NULL checks
    if (root->left) scavenged += scavenge_neighboring_rings(root->left, min_sites);
    if (root->right) scavenged += scavenge_neighboring_rings(root->right, min_sites);
    return scavenged;
}



// Deallocate the entire network
void delete_network(ring_t **root) {
    assert(root != NULL);
    if (*root == NULL) return;

    delete_network(&(*root)->left);
    delete_network(&(*root)->right);

    if ((*root)->site_list != NULL) {
        site_t *current = (*root)->site_list;
        site_t *start = current;
        do {
            site_t *next = current->next_site;
            free(current->site_name);
            free(current);
            current = next;
        } while (current != start);
    }

    free((*root)->ring_name);
    free(*root);
    *root = NULL;
}
