/*
 * Homework 9
 * Your Name
 * CS 240, Spring 2025
 * Purdue University
 */

/* Write your code here */

#include "hw9.h"

#include <assert.h>
#include <malloc.h>
#include <math.h>
#include <string.h>

void build_fort(char *name, int overrun, float north, float west,
                fort_t **head) {
  assert(name != NULL);
  assert(head != NULL);
  assert(*head == NULL);
  assert(north >= -100 && north <= 100);
  assert(west >= -20 && west <= 280);

  fort_t *new_fort = malloc(sizeof(fort_t));
  assert(new_fort != NULL);

  new_fort->name = malloc(strlen(name) + 1);
  assert(new_fort->name != NULL);
  strcpy(new_fort->name, name);

  new_fort->overrun_by_bandits = overrun;
  new_fort->distance_north = north;
  new_fort->distance_west = west;
  new_fort->resource_list = NULL;
  new_fort->covered_wagon_list = NULL;
  new_fort->next_fort = NULL;
  new_fort->prev_fort = NULL;

  *head = new_fort;
}

int chart_fort(fort_t **head, fort_t *new_fort) {
  assert(head != NULL);
  assert(new_fort != NULL);

  fort_t *current = *head;
  while (current != NULL) {
    if ((int)current->distance_west == (int)new_fort->distance_west &&
        (int)current->distance_north == (int)new_fort->distance_north) {
      return INVALID_LOCATION;
    }
    current = current->next_fort;
  }

  fort_t *prev = NULL;
  current = *head;
  while (current != NULL &&
         ((int)current->distance_west < (int)new_fort->distance_west ||
          ((int)current->distance_west == (int)new_fort->distance_west &&
           (int)current->distance_north < (int)new_fort->distance_north))) {
    prev = current;
    current = current->next_fort;
  }

  new_fort->prev_fort = prev;
  new_fort->next_fort = current;

  if (prev != NULL) {
    prev->next_fort = new_fort;
  } else {
    *head = new_fort;
  }

  if (current != NULL) {
    current->prev_fort = new_fort;
  }

  return OK;
}

void add_resource(fort_t *fort, enum resource_types_t type, float weight) {
    assert(fort != NULL);
    assert(type >= WATER && type <= MEDICINE);
    assert(weight > 0.0f);

    resource_t *new_res = malloc(sizeof(resource_t));
    assert(new_res != NULL);

    new_res->resource_type = type;
    new_res->weight = weight;
    new_res->next_resource = fort->resource_list;
    new_res->prev_resource = NULL;

    if(fort->resource_list)
        fort->resource_list->prev_resource = new_res;
    fort->resource_list = new_res;
}

void construct_wagon(char *name, int adults, int children, float capacity,
                     fort_t *fort) {
  assert(name != NULL);
  assert(fort != NULL);
  assert(adults > 0);
  assert(children >= 0);
  assert(capacity > 0);

  covered_wagon_t *new_wagon = malloc(sizeof(covered_wagon_t));
  assert(new_wagon != NULL);

  new_wagon->name = malloc(strlen(name) + 1);
  assert(new_wagon->name != NULL);
  strcpy(new_wagon->name, name);

  new_wagon->num_adults = adults;
  new_wagon->num_children = children;
  new_wagon->max_capacity = capacity;
  new_wagon->water_reserves = 0;
  new_wagon->food_reserves = 0;
  new_wagon->medicine_reserves = 0;

  covered_wagon_t *prev = NULL;
  covered_wagon_t *current = fort->covered_wagon_list;
  while (current != NULL && strcmp(current->name, name) < 0) {
    prev = current;
    current = current->next_covered_wagon;
  }

  new_wagon->prev_covered_wagon = prev;
  new_wagon->next_covered_wagon = current;

  if (prev != NULL) {
    prev->next_covered_wagon = new_wagon;
  } else {
    fort->covered_wagon_list = new_wagon;
  }

  if (current != NULL) {
    current->prev_covered_wagon = new_wagon;
  }
}

float collect_resources(fort_t *fort, char *wagon_name) {
  assert(fort != NULL);
  assert(wagon_name != NULL);

  covered_wagon_t *wagon = fort->covered_wagon_list;
  while (wagon != NULL && strcmp(wagon->name, wagon_name) != 0) {
    wagon = wagon->next_covered_wagon;
  }
  if (wagon == NULL) return NO_SUCH_WAGON;

  resource_t *current = fort->resource_list;
  resource_t *max_resources[3] = {NULL};

  while (current != NULL) {
    resource_t *next = current->next_resource;
    int type = current->resource_type;

    if (max_resources[type] == NULL ||
        current->weight > max_resources[type]->weight) {
      if (current->weight <= wagon->max_capacity) {
        max_resources[type] = current;
      }
    }
    current = next;
  }

  float total_weight = 0;
  for (int i = 0; i < 3; i++) {
    if (max_resources[i] != NULL) {
      if (max_resources[i]->prev_resource != NULL) {
        max_resources[i]->prev_resource->next_resource =
            max_resources[i]->next_resource;
      } else {
        fort->resource_list = max_resources[i]->next_resource;
      }
      if (max_resources[i]->next_resource != NULL) {
        max_resources[i]->next_resource->prev_resource =
            max_resources[i]->prev_resource;
      }

      switch (max_resources[i]->resource_type) {
        case WATER:
          wagon->water_reserves += max_resources[i]->weight;
          break;
        case FOOD:
          wagon->food_reserves += max_resources[i]->weight;
          break;
        case MEDICINE:
          wagon->medicine_reserves += max_resources[i]->weight;
          break;
      }
      total_weight += max_resources[i]->weight;
      free(max_resources[i]);
    }
  }

  return total_weight;
}

void demolish_fort(fort_t **fort_ptr) {
  assert(fort_ptr != NULL);
  assert(*fort_ptr != NULL);

  fort_t *fort = *fort_ptr;

  resource_t *resource = fort->resource_list;
  while (resource != NULL) {
    resource_t *next = resource->next_resource;
    free(resource);
    resource = next;
  }

  covered_wagon_t *wagon = fort->covered_wagon_list;
  while (wagon != NULL) {
    covered_wagon_t *next = wagon->next_covered_wagon;
    free(wagon->name);
    free(wagon);
    wagon = next;
  }

  if (fort->prev_fort != NULL) {
    fort->prev_fort->next_fort = fort->next_fort;
  }
  if (fort->next_fort != NULL) {
    fort->next_fort->prev_fort = fort->prev_fort;
  }

  if (*fort_ptr == fort) {
    *fort_ptr = fort->next_fort;
  }

  free(fort->name);
  free(fort);
}

int overrun_forts(fort_t **head) {
  assert(head != NULL);
  assert(*head != NULL);

  int count = 0;
  fort_t *current = *head;

  while (current != NULL) {
    fort_t *next = current->next_fort;
    if (current->overrun_by_bandits != 0) {
      demolish_fort(&current);
      count++;
    }
    current = next;
  }

  return count;
}

float manifest_destiny(fort_t **current_fort, char *wagon_name) {
  assert(current_fort != NULL);
  assert(*current_fort != NULL);
  assert(wagon_name != NULL);

  covered_wagon_t *wagon = (*current_fort)->covered_wagon_list;
  while (wagon != NULL && strcmp(wagon->name, wagon_name) != 0) {
    wagon = wagon->next_covered_wagon;
  }
  if (wagon == NULL) return NO_SUCH_WAGON;

  float total_distance = 0;

  while ((*current_fort)->next_fort != NULL) {
    fort_t *next_fort = (*current_fort)->next_fort;

    float dn = next_fort->distance_north - (*current_fort)->distance_north;
    float dw = next_fort->distance_west - (*current_fort)->distance_west;
    int distance = (int)sqrt(dn * dn + dw * dw);

    float water_needed = (WATER_PER_AD_PER_DIS * wagon->num_adults +
                          WATER_PER_CH_PER_DIS * wagon->num_children) *
                         distance;
    float food_needed = (FOOD_PER_AD_PER_DIS * wagon->num_adults +
                         FOOD_PER_CH_PER_DIS * wagon->num_children) *
                        distance;
    float med_needed = (MEDICINE_PER_AD_PER_DIS * wagon->num_adults +
                        MEDICINE_PER_CH_PER_DIS * wagon->num_children) *
                       distance;

    if (wagon->water_reserves < water_needed ||
        wagon->food_reserves < food_needed ||
        wagon->medicine_reserves < med_needed) {
      break;
    }

    wagon->water_reserves -= water_needed;
    wagon->food_reserves -= food_needed;
    wagon->medicine_reserves -= med_needed;

    if (wagon->prev_covered_wagon != NULL) {
      wagon->prev_covered_wagon->next_covered_wagon = wagon->next_covered_wagon;
    } else {
      (*current_fort)->covered_wagon_list = wagon->next_covered_wagon;
    }
    if (wagon->next_covered_wagon != NULL) {
      wagon->next_covered_wagon->prev_covered_wagon = wagon->prev_covered_wagon;
    }

    covered_wagon_t *prev = NULL;
    covered_wagon_t *curr = next_fort->covered_wagon_list;
    while (curr != NULL && strcmp(curr->name, wagon->name) < 0) {
      prev = curr;
      curr = curr->next_covered_wagon;
    }

    wagon->prev_covered_wagon = prev;
    wagon->next_covered_wagon = curr;
    if (prev != NULL) {
      prev->next_covered_wagon = wagon;
    } else {
      next_fort->covered_wagon_list = wagon;
    }
    if (curr != NULL) {
      curr->prev_covered_wagon = wagon;
    }

    *current_fort = next_fort;
    total_distance += distance;

    if (next_fort->overrun_by_bandits != 0) {
      return EATEN_BY_SASQUATCH;
    }
  }

  return total_distance;
}

void unmanifest_destiny(fort_t **head) {
  assert(head != NULL);
  assert(*head != NULL);

  fort_t *current = *head;
  fort_t *prev = NULL;

  while (current != NULL) {
    fort_t *next = current->next_fort;
    current->next_fort = prev;
    current->prev_fort = next;
    prev = current;
    current = next;
  }

  *head = prev;
}
