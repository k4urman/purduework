/*
 * Homework 9
 * Maninder (kaurman) Kaur
 * CS 240, Spring 2025
 * Purdue University
 */

/* Write your code here */

#include "hw9.h"

#include <assert.h>
#include <malloc.h>
#include <math.h>
#include <string.h>

/*
 * the function will initialize and fort_t struct
 * with the parameters provided for the game
 */

void build_fort(char *name, int overrun, float north, float west,
                fort_t **head) {
  assert(name != NULL);
  assert(head != NULL);
  assert(*head == NULL);
  assert((north >= -100) && (north <= 100));
  assert((west >= -20) && (west <= 280));

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
} /* build_fort() */

/*
 * this function will insert a fort_t into the
 * linked list (double) filled with fort structs
 * ordered and checked for duplicates
 */

int chart_fort(fort_t **head, fort_t *new_fort) {
  assert(head != NULL);
  assert(new_fort != NULL);

  fort_t *current = *head;
  while (current != NULL) {
    if (((int)current->distance_west == (int)new_fort->distance_west) &&
        ((int)current->distance_north == (int)new_fort->distance_north)) {
      return INVALID_LOCATION;
    }
    current = current->next_fort;
  }

  fort_t *prev = NULL;
  current = *head;
  while ((current != NULL) &&
         (((int)current->distance_west < (int)new_fort->distance_west) ||
          (((int)current->distance_west == (int)new_fort->distance_west) &&
           ((int)current->distance_north < (int)new_fort->distance_north)))) {
    prev = current;
    current = current->next_fort;
  }

  new_fort->prev_fort = prev;
  new_fort->next_fort = current;

  if (prev != NULL) {
    prev->next_fort = new_fort;
  }
  else {
    *head = new_fort;
  }

  if (current != NULL) {
    current->prev_fort = new_fort;
  }

  return OK;
} /* chart_fort() */

/*
 * this function will add a new resource to
 * the fort_t struct resource list, must be valid
 */

void add_resource(fort_t *fort, enum resource_types_t type, float weight) {
  assert(fort != NULL);
  assert((type >= WATER) && (type <= MEDICINE));
  assert(weight > 0.0f);

  resource_t *new_res = malloc(sizeof(resource_t));
  assert(new_res != NULL);

  new_res->resource_type = type;
  new_res->weight = weight;
  new_res->next_resource = fort->resource_list;
  new_res->prev_resource = NULL;

  if (fort->resource_list) {
    fort->resource_list->prev_resource = new_res;
  }
  fort->resource_list = new_res;
} /* add_resource() */

/*
 * this function will initilize new covered
 * wagon struct, adding to fort list in order
 * with valid parametees
 */

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
  while ((current != NULL) && (strcmp(current->name, name) < 0)) {
    prev = current;
    current = current->next_covered_wagon;
  }

  new_wagon->prev_covered_wagon = prev;
  new_wagon->next_covered_wagon = current;

  if (prev != NULL) {
    prev->next_covered_wagon = new_wagon;
  }
  else {
    fort->covered_wagon_list = new_wagon;
  }
  if (current != NULL) {
    current->prev_covered_wagon = new_wagon;
  }
} /* construct_wagon() */

/*
 * the function will get the heaviest weighted resources
 * from fort struct and remove them. Update list
 * for fort struct
 */

float collect_resources(fort_t *fort, char *wagon_name) {
  assert(fort != NULL);
  assert(wagon_name != NULL);

  covered_wagon_t *current_wagon = fort->covered_wagon_list;
  while (current_wagon && (strcmp(current_wagon->name, wagon_name) != 0)) {
    current_wagon = current_wagon->next_covered_wagon;
  }
  if (!current_wagon) return NO_SUCH_WAGON;

  float total_collected = 0;
  for (int resource_type = WATER; resource_type <= MEDICINE; resource_type++) {
    resource_t *current_resource = fort->resource_list;
    resource_t *heaviest_resource = NULL;
    float available_capacity =
        (resource_type == WATER)  ? current_wagon->water_reserves
        : (resource_type == FOOD) ? current_wagon->food_reserves
                                  : current_wagon->medicine_reserves;

    while (current_resource) {
      if ((current_resource->resource_type == resource_type) &&
          (current_resource->weight <=
              (current_wagon->max_capacity - available_capacity))) {
        if (!heaviest_resource ||
            (current_resource->weight > heaviest_resource->weight)) {
          heaviest_resource = current_resource;
        }
      }
      current_resource = current_resource->next_resource;
    }

    if (heaviest_resource) {
      if (resource_type == WATER) {
        current_wagon->water_reserves += heaviest_resource->weight;
      }
      else if (resource_type == FOOD) {
        current_wagon->food_reserves += heaviest_resource->weight;
      }
      else {
        current_wagon->medicine_reserves += heaviest_resource->weight;
      }

      if (heaviest_resource->prev_resource) {
        heaviest_resource->prev_resource->next_resource =
            heaviest_resource->next_resource;
      }
      if (heaviest_resource->next_resource) {
        heaviest_resource->next_resource->prev_resource =
            heaviest_resource->prev_resource;
      }
      if (fort->resource_list == heaviest_resource) {
        fort->resource_list = heaviest_resource->next_resource;
      }
      total_collected += heaviest_resource->weight;
      free(heaviest_resource);
    }
  }
  return total_collected;
} /* collect_resources() */

/*
 * this function removes the fort and
 * erases all memory of it
 */

void demolish_fort(fort_t **fort_ptr) {
  assert(fort_ptr != NULL);
  assert(*fort_ptr != NULL);

  fort_t *fort = *fort_ptr;

  if (fort->prev_fort != NULL) {
    fort->prev_fort->next_fort = fort->next_fort;
  }
  if (fort->next_fort != NULL) {
    fort->next_fort->prev_fort = fort->prev_fort;
  }

  fort_t *new_head = NULL;
  if (fort->prev_fort == NULL) {
    new_head = fort->next_fort;
  }
  else {
    new_head = fort->prev_fort;
    while (new_head->prev_fort != NULL) {
      new_head = new_head->prev_fort;
    }
  }

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

  free(fort->name);
  free(fort);

  *fort_ptr = new_head;
} /* demolish_fort() */

/*
 * this function will search and get rid
 * of fort_t that have been overrun_
 * by_bandits, removing the resources
 * and wagons
 */

int overrun_forts(fort_t **head) {
  assert(head != NULL);
  assert(*head != NULL);

  fort_t *current_fort = *head;
  while (current_fort->prev_fort) {
    current_fort = current_fort->prev_fort;
  }
  *head = current_fort;

  int count = 0;
  while (current_fort) {
    fort_t *next_fort = current_fort->next_fort;
    if (current_fort->overrun_by_bandits) {
      fort_t *fort_to_demolish = current_fort;
      current_fort = next_fort;
      demolish_fort(&fort_to_demolish);
      *head = fort_to_demolish;
      count++;
    }
    else {
      current_fort = next_fort;
    }
  }

  current_fort = *head;
  while (current_fort && current_fort->prev_fort) {
    current_fort = current_fort->prev_fort;
  }
  return count;
} /* overrun_forts() */

/*
 * this function will go through the joruney
 * and manage the resources of the fort_t
 * between the forts via multiple different
 * scenerios.
 */

float manifest_destiny(fort_t **current_fort_ptr, char *wagon_name) {
  assert(current_fort_ptr != NULL);
  assert(*current_fort_ptr != NULL);
  assert(wagon_name != NULL);

  fort_t *current_fort = *current_fort_ptr;
  covered_wagon_t *selected_wagon = NULL;
  float total_traveled_distance = 0.0f;

  covered_wagon_t *iterator = current_fort->covered_wagon_list;
  while (iterator != NULL) {
    if (strcmp(iterator->name, wagon_name) == 0) {
      selected_wagon = iterator;
      break;
    }
    iterator = iterator->next_covered_wagon;
  }

  if (selected_wagon == NULL) {
    *current_fort_ptr = current_fort;
    return NO_SUCH_WAGON;
  }

  while (1) {
    if (current_fort->overrun_by_bandits) {
      *current_fort_ptr = current_fort;
      return EATEN_BY_SASQUATCH;
    }

    if (current_fort->next_fort != NULL) {
      collect_resources(current_fort, wagon_name);
    }

    if (current_fort->next_fort == NULL) {
      *current_fort_ptr = current_fort;
      break;
    }

    fort_t *next_fort = current_fort->next_fort;

    if (next_fort->overrun_by_bandits) {
      *current_fort_ptr = next_fort;
      return EATEN_BY_SASQUATCH;
    }

    float delta_north =
        next_fort->distance_north - current_fort->distance_north;
    float delta_west = next_fort->distance_west - current_fort->distance_west;
    float calculated_distance =
        sqrtf(delta_north * delta_north + delta_west * delta_west);
    int integer_distance = (int)calculated_distance;

    float required_water =
        (WATER_PER_AD_PER_DIS * selected_wagon->num_adults +
         WATER_PER_CH_PER_DIS * selected_wagon->num_children) *
        integer_distance;
    float required_food = (FOOD_PER_AD_PER_DIS * selected_wagon->num_adults +
                           FOOD_PER_CH_PER_DIS * selected_wagon->num_children) *
                          integer_distance;
    float required_medicine =
        (MEDICINE_PER_AD_PER_DIS * selected_wagon->num_adults +
         MEDICINE_PER_CH_PER_DIS * selected_wagon->num_children) *
        integer_distance;

    if ((selected_wagon->water_reserves < required_water) ||
        (selected_wagon->food_reserves < required_food) ||
        (selected_wagon->medicine_reserves < required_medicine)) {
      *current_fort_ptr = current_fort;
      break;
    }

    selected_wagon->water_reserves -= required_water;
    selected_wagon->food_reserves -= required_food;
    selected_wagon->medicine_reserves -= required_medicine;

    if (selected_wagon->prev_covered_wagon != NULL) {
      selected_wagon->prev_covered_wagon->next_covered_wagon =
          selected_wagon->next_covered_wagon;
    }
    else {
      current_fort->covered_wagon_list = selected_wagon->next_covered_wagon;
    }

    if (selected_wagon->next_covered_wagon != NULL) {
      selected_wagon->next_covered_wagon->prev_covered_wagon =
          selected_wagon->prev_covered_wagon;
    }

    covered_wagon_t *new_position = next_fort->covered_wagon_list;
    covered_wagon_t *previous_wagon = NULL;

    while ((new_position != NULL) &&
           (strcmp(selected_wagon->name, new_position->name) > 0)) {
      previous_wagon = new_position;
      new_position = new_position->next_covered_wagon;
    }

    selected_wagon->next_covered_wagon = new_position;
    selected_wagon->prev_covered_wagon = previous_wagon;

    if (previous_wagon == NULL) {
      next_fort->covered_wagon_list = selected_wagon;
    }
    else {
      previous_wagon->next_covered_wagon = selected_wagon;
    }

    if (new_position != NULL) {
      new_position->prev_covered_wagon = selected_wagon;
    }

    total_traveled_distance += calculated_distance;
    current_fort = next_fort;
  }

  *current_fort_ptr = current_fort;
  return total_traveled_distance;
} /* manifest_destiny() */

/*
 * this function will reverse the order of
 * the linked list.
 */

void unmanifest_destiny(fort_t **head) {
  assert(head != NULL);
  assert(*head != NULL);

  fort_t *current = *head;
  while (current->prev_fort != NULL) {
    current = current->prev_fort;
  }

  fort_t *temp = NULL;
  fort_t *new_head = NULL;

  while (current != NULL) {
    temp = current->next_fort;
    current->next_fort = current->prev_fort;
    current->prev_fort = temp;

    new_head = current;
    current = temp;
  }

  *head = new_head;
} /* unmanifest_destiny() */
