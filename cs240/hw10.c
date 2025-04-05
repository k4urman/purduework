/* 74%
 * Homework 10
 * Your Name
 * CS 240, Spring 2025
 * Purdue University
 */

/* Write your code here */

#include <assert.h>
#include <malloc.h>
#include <string.h>
#include "hw10.h"

// Helper function to insert a child into a sorted sibling list by birth year
static void insert_child(person_t *parent, person_t *new_child) {
    if (!parent->first_child) {
        parent->first_child = new_child;
        return;
    }

    person_t *curr = parent->first_child;
    person_t *prev = NULL;

    while (curr && (curr->birth_year < new_child->birth_year ||
           (curr->birth_year == new_child->birth_year && strcmp(curr->name, new_child->name) <= 0))) {
        prev = curr;
        curr = curr->next_sibling;
    }

    if (prev) {
        prev->next_sibling = new_child;
        new_child->next_sibling = curr;
    } else {
        new_child->next_sibling = parent->first_child;
        parent->first_child = new_child;
    }
}

// Helper function to print indentation
static void print_indent(int level) {
    for (int i = 0; i < level; i++) {
        printf("    ");
    }
}

// Helper to collect all ancestors recursively with cycle detection
static void collect_ancestors(person_t *p, person_t **ancestors, int *count, int max, person_t **visited, int *v_count) {
    if (!p || *count >= max) return;

    for (int i = 0; i < *v_count; i++) {
        if (visited[i] == p) return; // Avoid cycles
    }
    visited[(*v_count)++] = p;

    ancestors[(*count)++] = p;
    collect_ancestors(p->father, ancestors, count, max, visited, v_count);
    if (p->mother != p->father) {
        collect_ancestors(p->mother, ancestors, count, max, visited, v_count);
    }
}

person_t *create_person(char *name, int birth_year, person_t *father, person_t *mother) {
    assert(name != NULL);
    assert(birth_year >= 0);

    person_t *p = (person_t *)malloc(sizeof(person_t));
    assert(p != NULL);

    p->name = (char *)malloc(strlen(name) + 1);
    assert(p->name != NULL);
    strcpy(p->name, name);
    p->birth_year = birth_year;
    p->father = father;
    p->mother = mother;
    p->first_child = NULL;
    p->next_sibling = NULL;

    if (father) {
        insert_child(father, p);
    }
    if (mother && mother != father) {
        insert_child(mother, p);
    }

    return p;
}

person_t *get_parent(person_t *person, enum parent parent_type) {
    assert(person != NULL);
    assert(parent_type == MOTHER || parent_type == FATHER);

    return (parent_type == MOTHER) ? person->mother : person->father;
}

person_t *get_common_ancestor(person_t *p1, person_t *p2) {
    assert(p1 != NULL);
    assert(p2 != NULL);

    person_t *ancestors1[1000] = {0};
    int count1 = 0;
    person_t *visited1[1000] = {0};
    int v_count1 = 0;
    collect_ancestors(p1, ancestors1, &count1, 1000, visited1, &v_count1);

    person_t *ancestors2[1000] = {0};
    int count2 = 0;
    person_t *visited2[1000] = {0};
    int v_count2 = 0;
    collect_ancestors(p2, ancestors2, &count2, 1000, visited2, &v_count2);

    for (int i = 0; i < count1; i++) {
        for (int j = 0; j < count2; j++) {
            if (ancestors1[i] == ancestors2[j]) {
                return ancestors1[i]; // First match is closest
            }
        }
    }

    return NULL;
}

void print_ancestry(person_t *person, int depth) {
    assert(person != NULL);
    assert(depth >= -1);

    printf("%s\n", person->name);
    if (depth == 0 || (!person->father && !person->mother)) return;

    int next_depth = (depth == -1) ? -1 : depth - 1;

    if (person->father) {
        print_indent(1);
        printf("I- %s\n", person->father->name);
        if (next_depth != 0) {
            print_ancestry(person->father, next_depth);
        }
    }
    if (person->mother && person->mother != person->father) {
        print_indent(1);
        printf("I- %s\n", person->mother->name);
        if (next_depth != 0) {
            print_ancestry(person->mother, next_depth);
        }
    }
}

void print_descendants(person_t *person, int depth) {
    assert(person != NULL);
    assert(depth >= -1);

    printf("%s\n", person->name);
    if (depth == 0 || !person->first_child) return;

    int next_depth = (depth == -1) ? -1 : depth - 1;
    person_t *child = person->first_child;

    while (child) {
        print_indent(1);
        printf("I- %s\n", child->name);
        if (next_depth != 0) {
            print_descendants(child, next_depth);
        }
        child = child->next_sibling;
    }
}

person_t *find_oldest_ancestor(person_t *person) {
    assert(person != NULL);

    if (!person->father && !person->mother) {
        return NULL; // No ancestors
    }

    person_t *oldest = NULL;

    if (person->father) {
        person_t *father_oldest = find_oldest_ancestor(person->father);
        if (father_oldest) {
            if (!oldest || father_oldest->birth_year < oldest->birth_year ||
                (father_oldest->birth_year == oldest->birth_year && strcmp(father_oldest->name, oldest->name) < 0)) {
                oldest = father_oldest;
            }
        } else {
            if (!oldest || person->father->birth_year < oldest->birth_year ||
                (person->father->birth_year == oldest->birth_year && strcmp(person->father->name, oldest->name) < 0)) {
                oldest = person->father;
            }
        }
    }

    if (person->mother && person->mother != person->father) {
        person_t *mother_oldest = find_oldest_ancestor(person->mother);
        if (mother_oldest) {
            if (!oldest || mother_oldest->birth_year < oldest->birth_year ||
                (mother_oldest->birth_year == oldest->birth_year && strcmp(mother_oldest->name, oldest->name) < 0)) {
                oldest = mother_oldest;
            }
        } else {
            if (!oldest || person->mother->birth_year < oldest->birth_year ||
                (person->mother->birth_year == oldest->birth_year && strcmp(person->mother->name, oldest->name) < 0)) {
                oldest = person->mother;
            }
        }
    }

    return oldest;
}

person_t **get_cousins(person_t *person, int *num_cousins) {
    assert(person != NULL);
    assert(num_cousins != NULL);

    *num_cousins = 0;
    person_t *parents[2] = {person->father, person->mother};
    person_t *cousins[1000] = {0};

    for (int i = 0; i < 2; i++) {
        if (!parents[i]) continue;
        person_t *grandparent = parents[i]->father ? parents[i]->father : parents[i]->mother;
        if (!grandparent) continue;

        person_t *aunt_uncle = grandparent->first_child;
        while (aunt_uncle) {
            if (aunt_uncle != parents[i]) {
                person_t *cousin = aunt_uncle->first_child;
                while (cousin) {
                    cousins[*num_cousins] = cousin;
                    (*num_cousins)++;
                    cousin = cousin->next_sibling;
                }
            }
            aunt_uncle = aunt_uncle->next_sibling;
        }
    }

    if (*num_cousins == 0) return NULL;

    person_t **result = (person_t **)malloc(*num_cousins * sizeof(person_t *));
    assert(result != NULL);
    for (int i = 0; i < *num_cousins; i++) {
        result[i] = cousins[i];
    }

    for (int i = 0; i < *num_cousins - 1; i++) {
        for (int j = i + 1; j < *num_cousins; j++) {
            if (result[i]->birth_year > result[j]->birth_year ||
                (result[i]->birth_year == result[j]->birth_year && strcmp(result[i]->name, result[j]->name) > 0)) {
                person_t *temp = result[i];
                result[i] = result[j];
                result[j] = temp;
            }
        }
    }

    return result;
}

void delete_tree(person_t **root) {
    assert(root != NULL);
    assert(*root != NULL);

    person_t *person = *root;

    person_t *child = person->first_child;
    while (child) {
        if (child->father == person) child->father = NULL;
        if (child->mother == person) child->mother = NULL;
        child = child->next_sibling;
    }

    if (person->father) delete_tree(&person->father);
    if (person->mother && person->mother != person->father) delete_tree(&person->mother);

    person_t *sibling = person->next_sibling;
    while (sibling) {
        person_t *next = sibling->next_sibling;
        free(sibling->name);
        free(sibling);
        sibling = next;
    }

    free(person->name);
    free(person);
    *root = NULL;
}
