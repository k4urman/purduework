/*
 * Homework 12
 * Your Name
 * CS 240, Spring 2025
 * Purdue University
 */

#include "hw12.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#define _POSIX_C_SOURCE 200809L
#include <string.h>

/*
 * Function to print the internal data of a spellbook_t struct passed as a void
 * pointer to standard out.
 */
void print_spellbook(void *p) {
  spellbook_t *ptr = (spellbook_t *) p;
  assert(ptr && ptr->title);
  printf("Title: %s\nSpell Count: %d\nArcane Density: %.2f\n"
         "Year Written: %04d\n",
         ptr->title, ptr->spell_count, ptr->arcane_density, ptr->year_written);
} /* print_spellbook() */

/*
 * Function to print the internal data of an ai_core_t struct passed as a void
 * pointer to standard out.
 */
void print_ai_core(void *p) {
  ai_core_t *ptr = (ai_core_t *) p;
  assert(ptr && ptr->model_id);
  printf("Model ID: %s\nProcessor Speed: %.2f\nNumber of Algorithms: %d\n"
         "Firmware Version: %d\n",
         ptr->model_id, ptr->processor_speed, ptr->num_algorithms,
         ptr->firmware_version);
} /* print_ai_core() */

/*
 * Function to print a tree node by dynamically dispatching the print function
 * stored in the node on the data stored in the node
 */
void print_node(node_t *n_ptr) {
  assert(n_ptr && n_ptr->data && n_ptr->print);
  (n_ptr->print)(n_ptr->data);
} /* print_node() */

/*
 * Function to recursively print the tree using an in-order traversal
 */
void print_tree(node_t *root) {
  if (!root) {
    return;
  }
  print_tree(root->left_child);
  print_node(root);
  print_tree(root->right_child);
} /* print_tree() */

void create_node(node_t **node, void *data, void (*print)(void *), void (*delete)(void **), int (*compare)(void *, void *)) {
    assert(node != NULL && *node == NULL);
    assert(data != NULL && print != NULL && delete != NULL && compare != NULL);

    *node = (node_t *)malloc(sizeof(node_t));
    assert(*node != NULL);

    (*node)->left_child = NULL;
    (*node)->right_child = NULL;
    (*node)->data = data;
    (*node)->print = print;
    (*node)->delete = delete;
    (*node)->compare = compare;
}

void delete_node(node_t **node) {
    assert(node != NULL && *node != NULL);
    assert((*node)->left_child == NULL && (*node)->right_child == NULL);

    (*node)->delete(&(*node)->data);
    free(*node);
    *node = NULL;
}

void insert_node(node_t **root, node_t *new_node) {
    assert(root != NULL && new_node != NULL);

    if (*root == NULL) {
        *root = new_node;
        return;
    }

    int cmp = (*root)->compare((*root)->data, new_node->data);
    if (cmp >= 0) {
        insert_node(&(*root)->left_child, new_node);
    } else {
        insert_node(&(*root)->right_child, new_node);
    }
}

node_t **find_nodes(node_t *root, void *target, int *count) {
    assert(root != NULL && target != NULL && count != NULL);

    *count = 0;

    // First pass: count matching nodes using prefix traversal
    void count_matches(node_t *node) {
        if (node == NULL) return;
        if (node->compare(node->data, target) == 0) (*count)++;
        count_matches(node->left_child);
        count_matches(node->right_child);
    }
    count_matches(root);

    // Allocate array for matching nodes
    node_t **result = (node_t **)malloc(*count * sizeof(node_t *));
    assert(result != NULL);

    // Second pass: collect matching nodes
    int index = 0;
    void collect_matches(node_t *node) {
        if (node == NULL) return;
        if (node->compare(node->data, target) == 0) {
            result[index++] = node;
        }
        collect_matches(node->left_child);
        collect_matches(node->right_child);
    }
    collect_matches(root);

    return result;
}

void delete_tree(node_t **root) {
    assert(root != NULL);

    if (*root == NULL) {
        return;
    }

    delete_tree(&(*root)->left_child);
    delete_tree(&(*root)->right_child);
    delete_node(root);
}

void remove_node(node_t **root, node_t *target) {
    assert(root != NULL && *root != NULL && target != NULL);

    node_t *current = *root;
    node_t **parent_link = root;

    // Find the target node
    while (current != NULL && current != target) {
        int cmp = current->compare(current->data, target->data);
        if (cmp >= 0) {
            parent_link = &current->left_child;
            current = current->left_child;
        } else {
            parent_link = &current->right_child;
            current = current->right_child;
        }
    }

    if (current == NULL) {
        return;
    }

    // Case 1: Leaf node
    if (current->left_child == NULL && current->right_child == NULL) {
        *parent_link = NULL;
        delete_node(&current);
        return;
    }

    // Case 2: Node with only right child
    if (current->left_child == NULL) {
        *parent_link = current->right_child;
        current->right_child = NULL;
        delete_node(&current);
        return;
    }

    // Case 3: Node with only left child
    if (current->right_child == NULL) {
        *parent_link = current->left_child;
        current->left_child = NULL;
        delete_node(&current);
        return;
    }

    // Case 4: Node with two children
    node_t *predecessor = current->left_child;
    node_t **predecessor_link = &current->left_child;

    while (predecessor->right_child != NULL) {
        predecessor_link = &predecessor->right_child;
        predecessor = predecessor->right_child;
    }

    *predecessor_link = predecessor->left_child;
    predecessor->left_child = current->left_child;
    predecessor->right_child = current->right_child;

    *parent_link = predecessor;
    current->left_child = NULL;
    current->right_child = NULL;
    delete_node(&current);
}

static char *my_strdup(const char *s) {
    size_t len = strlen(s) + 1;
    char *new = malloc(len);
    assert(new != NULL);
    memcpy(new, s, len);
    return new;
}

void create_spellbook(void **data, const char *title, int spell_count, float arcane_density, int year_written) {
    assert(data != NULL && *data == NULL && title != NULL);

    spellbook_t *book = (spellbook_t *)malloc(sizeof(spellbook_t));
    assert(book != NULL);

    book->title = my_strdup(title);
    assert(book->title != NULL);
    book->spell_count = spell_count;
    book->arcane_density = arcane_density;
    book->year_written = year_written;

    *data = (void *)book;
}

void delete_spellbook(void **data) {
    assert(data != NULL && *data != NULL);

    spellbook_t *book = (spellbook_t *)*data;
    free(book->title);
    free(book);
    *data = NULL;
}

int compare_spellbooks(void *data1, void *data2) {
    assert(data1 != NULL && data2 != NULL);

    spellbook_t *book1 = (spellbook_t *)data1;
    spellbook_t *book2 = (spellbook_t *)data2;

    float potency1 = book1->arcane_density * book1->spell_count / (float)(CURRENT_YEAR - book1->year_written + 1);
    float potency2 = book2->arcane_density * book2->spell_count / (float)(CURRENT_YEAR - book2->year_written + 1);

    if (potency1 > potency2) return 1;
    if (potency1 < potency2) return -1;
    return 0;
}

void create_ai_core(void **data, const char *model_id, float processor_speed, int num_algorithms, int firmware_version) {
    assert(data != NULL && *data == NULL && model_id != NULL);

    ai_core_t *core = (ai_core_t *)malloc(sizeof(ai_core_t));
    assert(core != NULL);

    core->model_id = my_strdup(model_id);
    assert(core->model_id != NULL);
    core->processor_speed = processor_speed;
    core->num_algorithms = num_algorithms;
    core->firmware_version = firmware_version;

    *data = (void *)core;
}

void delete_ai_core(void **data) {
    assert(data != NULL && *data != NULL);

    ai_core_t *core = (ai_core_t *)*data;
    free(core->model_id);
    free(core);
    *data = NULL;
}

int compare_ai_cores(void *data1, void *data2) {
    assert(data1 != NULL && data2 != NULL);

    ai_core_t *core1 = (ai_core_t *)data1;
    ai_core_t *core2 = (ai_core_t *)data2;

    float efficiency1 = core1->processor_speed * core1->num_algorithms / (float)(CURRENT_YEAR - core1->firmware_version + 1);
    float efficiency2 = core2->processor_speed * core2->num_algorithms / (float)(CURRENT_YEAR - core2->firmware_version + 1);

    if (efficiency1 > efficiency2) return 1;
    if (efficiency1 < efficiency2) return -1;
    return 0;
}
