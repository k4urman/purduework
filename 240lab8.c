#ifndef HW8_H
#define HW8_H

/*
 * Homework 8 header file
 * CS 240, Spring 2025
 * Purdue University
 */

#define SUCCESS      (-1)
#define NOT_FOUND    (-2)
#define INVALID_MOVE (-3)

/* Data structures */

typedef struct substance_struct {
  char *name;
  char *origin;
  double potency;
  struct substance_struct *next;
} substance_t;

typedef struct potion_struct {
  char *name;
  char *effect_pattern;
  double total_potency;
  struct substance_struct *substance_list;
  struct potion_struct *next;
} potion_t;

/* Functions */

substance_t *create_substance(char *, char *, double);
potion_t *create_potion(char *, char *);
int add_substance(potion_t *, char *, substance_t *);
substance_t *remove_substance(potion_t *, substance_t *);
int move_substances(potion_t *, char *, char *, substance_t *);
substance_t *substance_source(potion_t *, char *);
potion_t *highest_substance_potion(potion_t *);
int remove_potent_substances(potion_t *, char *, double);
int purify_potions(potion_t **, char);
int cursed_potions(potion_t **, char *);

#endif // HW8_H

/*
 * Homework 8
 * Maninder (Kaurman) Kaur
 * CS 240, Spring 2025
 * Purdue University
 */

/* Write your code here */

#include "hw8.h"

#include <assert.h>
#include <malloc.h>
#include <string.h>

/*
 * this functions allocates and initializes
 * a substance with given name, origin, and
 * potency, returning a pointer to the new substance
 */

substance_t *create_substance(char *substance_name, char *origin,
                              double potency) {
  assert(substance_name && origin && (potency >= 0));
  substance_t *sub = malloc(sizeof(substance_t));
  assert(sub);
  sub->name = malloc(strlen(substance_name) + 1);
  assert(sub->name);
  strcpy(sub->name, substance_name);
  sub->origin = malloc(strlen(origin) + 1);
  assert(sub->origin);
  strcpy(sub->origin, origin);
  sub->potency = potency;
  sub->next = NULL;
  return sub;
}/* create_substance() */

/*
 * this function creates a potion
 * container with specified name and validated
 * effect pattern, initializing its substance
 * list and total potency.
 */

potion_t *create_potion(char *potion_name, char *effect_pattern) {
  assert((potion_name) && (effect_pattern));

  for (char *c = effect_pattern; *c; c++) {
    assert(((*c == '@') || (*c == '*') || (*c == '+')));
  }

  potion_t *potion = malloc(sizeof(potion_t));
  assert(potion);

  potion->name = malloc(strlen(potion_name) + 1);
  assert(potion->name);
  strcpy(potion->name, potion_name);

  potion->effect_pattern = malloc(strlen(effect_pattern) + 1);
  assert(potion->effect_pattern);
  strcpy(potion->effect_pattern, effect_pattern);

  potion->total_potency = 0.0;
  potion->substance_list = NULL;
  potion->next = NULL;
  return potion;
} /* create_potion() */

/*
 * this function inserts a substance into
 * a potion's sorted list (descending potency order),
 * avoiding duplicates, and updates total potency.
 */

int add_substance(potion_t *potions, char *potion_name,
                  substance_t *substance) {
  assert(potions);
  assert(potion_name);
  assert(substance);
  potion_t *potion = potions;
  while (potion && strcmp(potion->name, potion_name)) potion = potion->next;
  if (!potion) return NOT_FOUND;
  substance_t *current = potion->substance_list;
  while (current) {
    if (strcmp(current->name, substance->name) == 0) return INVALID_MOVE;
    current = current->next;
  }
  substance_t **current_ptr = &potion->substance_list;
  while (*current_ptr && ((*current_ptr)->potency > substance->potency)) {
    current_ptr = &(*current_ptr)->next;
  }
  while (*current_ptr && ((*current_ptr)->potency == substance->potency)) {
    current_ptr = &(*current_ptr)->next;
  }
  substance->next = *current_ptr;
  *current_ptr = substance;
  potion->total_potency += substance->potency;
  return SUCCESS;
} /* add_substance() */

/*
 * this function detaches a specified
 * substance from a potion's list, adjusts
 * total potency, and returns the removed substance.
 */

substance_t *remove_substance(potion_t *potion, substance_t *substance) {
  assert((potion) && (substance));

  substance_t **prev_ptr = &potion->substance_list;
  substance_t *current = *prev_ptr;

  while (current) {
    if (current == substance) {
      *prev_ptr = current->next;
      current->next = NULL;
      potion->total_potency -= current->potency;
      return current;
    }
    prev_ptr = &current->next;
    current = current->next;
  }
  return NULL;
} /* remove_substance() */

/*
 * this function transfers a substance
 * between two potions while maintaining sorted
 * order, checking for validity and duplicates.
 */

int move_substances(potion_t *potions, char *from_name, char *to_name,
                    substance_t *substance) {
  assert((potions) && (from_name) && (to_name) && (substance));

  potion_t *from = NULL;
  potion_t *to = NULL;

  for (potion_t *p = potions; p && (!from || !to); p = p->next) {
    if (strcmp(p->name, from_name) == 0) from = p;
    if (strcmp(p->name, to_name) == 0) to = p;
  }

  if (!from || !to) return NOT_FOUND;

  substance_t **prev = &from->substance_list;
  substance_t *curr = *prev;

  while (curr && (curr != substance)) {
    prev = &curr->next;
    curr = curr->next;
  }

  if (!curr) return NOT_FOUND;

  for (substance_t *s = to->substance_list; s; s = s->next) {
    if (strcmp(s->name, substance->name) == 0) return INVALID_MOVE;
  }

  *prev = substance->next;
  substance->next = NULL;
  from->total_potency -= substance->potency;

  substance_t **insert = &to->substance_list;
  while ((*insert) && ((*insert)->potency > substance->potency)) {
    insert = &(*insert)->next;
  }

  while ((*insert) && ((*insert)->potency == substance->potency)) {
    insert = &(*insert)->next;
  }

  substance->next = *insert;
  *insert = substance;
  to->total_potency += substance->potency;
  return SUCCESS;
} /* move_substances() */

/*
 * this function extracts all substances
 * from a specified origin across all potions,
 * returning a sorted list by potency.
 */

substance_t *substance_source(potion_t *potions, char *origin) {
  assert((potions) && (origin));

  substance_t *result = NULL;
  for (potion_t *p = potions; p; p = p->next) {
    substance_t **curr = &p->substance_list;

    while (*curr) {
      substance_t *s = *curr;
      if (strcmp(s->origin, origin) == 0) {
        *curr = s->next;
        p->total_potency -= s->potency;
        s->next = NULL;

        substance_t **insert = &result;
        while ((*insert) && ((*insert)->potency > s->potency)) {
          insert = &(*insert)->next;
        }

        while ((*insert) && ((*insert)->potency == s->potency)) {
          insert = &(*insert)->next;
        }

        s->next = *insert;
        *insert = s;
      }
      else {
        curr = &(*curr)->next;
      }
    }
  }
  return result;
} /* substance_source() */

/*
 * this function dentifies the potion
 * with the most substances, using total potency
 * and creation order as tiebreakers.
 */

potion_t *highest_substance_potion(potion_t *potions) {
  assert(potions);

  potion_t *max_potion = NULL;
  int max_count = -1;
  double min_total = 0;

  for (potion_t *p = potions; p; p = p->next) {
    int count = 0;
    for (substance_t *s = p->substance_list; s; s = s->next) {
      count++;
    }

    if ((count > max_count) ||
        ((count == max_count) &&
         ((p->total_potency < min_total) ||
          ((p->total_potency == min_total) && (!max_potion))))) {
      max_count = count;
      max_potion = p;
      min_total = p->total_potency;
    }
  }
  return max_potion;
} /* highest_substance_potion() */

/*
 * this function removes substances
 * exceeding a potency threshold from potions
 * matching a specific effect pattern.
 */

int remove_potent_substances(potion_t *potions, char *effect_pattern,
                             double max_potency) {
  assert(potions && effect_pattern);
  assert(max_potency >= 0);

  int found_potion = 0;  // Now properly used

  for (potion_t *p = potions; p; p = p->next) {
    if (strcmp(p->effect_pattern, effect_pattern) == 0) {
      substance_t **curr = &p->substance_list;
      while (*curr) {
        if ((*curr)->potency > max_potency) {
          substance_t *delete = *curr;
          *curr = delete->next;
          p->total_potency -= delete->potency;
          free(delete->name);
          free(delete->origin);
          free(delete);
          found_potion++;
        }
        else {
          curr = &(*curr)->next;
        }
      }
    }
  }
  return found_potion > 0 ? SUCCESS : NOT_FOUND;
} /* remove_potent_substances() */

/*
 * this function deletes potions dominated
 * by a specified effect character, freeing
 * all associated resources.
 */

int purify_potions(potion_t **potions, char effect) {
  assert(potions && *potions &&
         ((effect == '@') || (effect == '*') || (effect == '+')));
  int count = 0;
  potion_t **curr = potions;
  while (*curr) {
    potion_t *p = *curr;
    int a = 0;
    int s = 0;
    int p_count = 0;
    for (char *c = p->effect_pattern; *c; c++) {
      if (*c == '@') {
        a++;
      }
      else if (*c == '*') {
        s++;
      }
      else {
        p_count++;
      }
    }
    char dom = ((a > s) && (a > p_count)) ? '@' : (s > p_count) ? '*' : '+';
    if (dom == effect) {
      *curr = p->next;
      for (substance_t *sub = p->substance_list; sub; ) {
        substance_t *next = sub->next;
        free(sub->name);
        free(sub->origin);
        free(sub);
        sub = next;
      }
      free(p->name);
      free(p->effect_pattern);
      free(p);
      count++;
    }
    else {
      curr = &(*curr)->next;
    }
  }
  return count ? count : NOT_FOUND;
} /* purify_potions() */

/*
 * this function removes all potions
 * containing substances from a banned origin,
 * returning the count of destroyed potions.
 */

int cursed_potions(potion_t **potions, char *cursed_origin) {
  assert(potions && *potions && cursed_origin);
  int count = 0;
  potion_t **curr = potions;
  while (*curr) {
    potion_t *p = *curr;
    int found = 0;
    for (substance_t *s = p->substance_list; s && !found; s = s->next) {
      if (strcmp(s->origin, cursed_origin) == 0) {
        found = 1;
      }
    }
    if (found) {
      *curr = p->next;
      for (substance_t *s = p->substance_list; s; ) {
        substance_t *next = s->next;
        free(s->name);
        free(s->origin);
        free(s);
        s = next;
      }
      free(p->name);
      free(p->effect_pattern);
      free(p);
      count++;
    }
    else {
      curr = &(*curr)->next;
    }
  }
  return count ? count : NOT_FOUND;
} /* cursed_potions() */
