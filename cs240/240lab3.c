#ifndef HW3_H
#define HW3_H

#define MAX_RENTALS (200)
#define MAX_BUF_LEN (50)

#define MIN_YEAR (1900)
#define MAX_YEAR (2038)

#define OK (-1)
#define FILE_READ_ERR (-2)
#define NO_DATA_POINTS (-3)
#define BAD_DATA (-4)
#define FILE_WRITE_ERR (-5)
#define OUT_OF_BOUNDS (-6)
#define NOT_FOUND (-7)

/*
 * Global variable declarations.
 * You must also define these in your hw3.c file.
 */

// 0: Customer Name
// 1: Start Date
// 2: End Date

extern char g_rental_history[MAX_RENTALS][3][MAX_BUF_LEN];

// 0: VIN
// 1: Make
// 2: Model

extern char g_vehicle_info[MAX_RENTALS][3][MAX_BUF_LEN];

// 0: Miles Traveled
// 1: Rating
// 2: Customer Fee
// 3: Maintenance Cost

extern float g_rental_stats[MAX_RENTALS][4];
extern int g_rental_count;

int read_tables(char *file_name);
float get_total_miles (char *vin);
float avg_brand_satisfaction(char *make);
float avg_maintenance_cost (char *make, char *model);
int retire_vehicles(float miles,
                    char retirable_vehicles[MAX_RENTALS][MAX_BUF_LEN]);
int popular_make_model();
float calc_vehicle_profitability(char *vin);
int generate_customer_report(char *out_file, char *customer_name);

#endif // HW3_H


/*
 * Homework 3
 * Maninder (Kaurman) Kaur
 * CS 240, Spring 2025
 * Purdue University
 */

/* Write your code here */
#include "hw3.h"

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Definitions and Variables */

#define GOOD_DATE_PARSE (3)
#define MIN_DAY (1)
#define MAX_DAY (30)
#define MIN_MONTH (1)
#define MAX_MONTH (12)
#define MIN_BUF_LEN (0)
#define MAX_BUF_VIN (18)
#define MIN_MILES (0)
#define MIN_RATING (0.0)
#define MAX_RATING (10.0)
#define MIN_FEE (0.0)
#define MIN_MAINTENANCE_COST (0.0)
#define EXPECTED_PARSED (10)

char g_rental_history[MAX_RENTALS][3][MAX_BUF_LEN] = {};
char g_vehicle_info[MAX_RENTALS][3][MAX_BUF_LEN] = {};
float g_rental_stats[MAX_RENTALS][4] = {};
int g_rental_count = 0;

/*
 * This function parses date used later
 */

int parse_date(const char *date_str, int *year, int *month, int *day) {
  return (sscanf(date_str, "%d-%d-%d", year, month, day));
} /* parse_date() */

/*
 * Checks if a character is an uppercase letter.
 */

int is_up(char c) {
  return ((c >= 'A') && (c <= 'Z'));
} /* is_up() */

/*
 * Checks if a character is a digit.
 */

int is_digit(char c) {
  return ((c >= '0') && (c <= '9'));
} /* is_digit() */

/*
 * Checks the VIN if it's is_up or is_digit
 */

int check_vin(const char *vin_str) {
  int str_size = strlen(vin_str);

  for (int i = 0; i < str_size; i++) {
    if (!(is_up(vin_str[i]) || is_digit(vin_str[i]))) return BAD_DATA;
  }
  return OK;
} /* check_vin() */

/*
 * Checks tables
 */

int read_tables(char *file_name) {
  FILE *file = fopen(file_name, "r");
  if (!file) {
    return FILE_READ_ERR;
  }
  bool has_records = 0;
  int count = 0;
  char customer_name[MAX_BUF_LEN] = {};
  char start_date[MAX_BUF_LEN] = {};
  int start_day = 0;
  int start_month = 0;
  int start_year = 0;
  char end_date[MAX_BUF_LEN] = {};
  int end_day = 0;
  int end_month = 0;
  int end_year = 0;
  char vin[MAX_BUF_LEN] = {};
  char make[MAX_BUF_LEN] = {};
  char model[MAX_BUF_LEN] = {};
  float miles = 0.0;
  float rating = 0.0;
  float customer_fee = 0.0;
  float maintenance_cost = 0.0;
  int parsed = 0;
  while ((parsed = fscanf(file,
                         "%49[^|]|%49[^|]|%49[^|]|%17[^,],"
                         "%49[^,],%49[^|]|%f|%f|%f|%f\n",
                         customer_name, start_date, end_date,
                         vin, make, model, &miles, &rating,
                         &customer_fee, &maintenance_cost)) != EOF) {
    if (count == MAX_RENTALS) {
      fclose(file);
      file = NULL;
      return OUT_OF_BOUNDS;
    }

    if (parsed != EXPECTED_PARSED) {
      fclose(file);
      file = NULL;
      return BAD_DATA;
    }

    if ((strlen(customer_name) <= MIN_BUF_LEN) ||
        (strlen(customer_name) >= MAX_BUF_LEN ) ||
        (strlen(start_date) >= MAX_BUF_LEN) ||
        (strlen(start_date) <= MIN_BUF_LEN) ||
        (strlen(end_date) >= MAX_BUF_LEN) ||
        (strlen(end_date) <= MIN_BUF_LEN) ||
        (strlen(vin) >= MAX_BUF_VIN) || (strlen(vin) <= MIN_BUF_LEN) ||
        (strlen(make) >= MAX_BUF_LEN) || (strlen(make) <= MIN_BUF_LEN) ||
        (strlen(model) >= MAX_BUF_LEN) || (strlen(model) <= MIN_BUF_LEN)) {
      fclose(file);
      file = NULL;
      return BAD_DATA;
    }

    if (check_vin(vin) == BAD_DATA) {
      fclose(file);
      file = NULL;
      return BAD_DATA;
    }

    if ((miles < MIN_MILES) || (rating < MIN_RATING) ||
        (rating > MAX_RATING) || (customer_fee < MIN_FEE) ||
        (maintenance_cost < MIN_MAINTENANCE_COST)) {
      fclose(file);
      file = NULL;
      return BAD_DATA;
    }

    if ((parse_date(start_date, &start_year,
                    &start_month, &start_day) == GOOD_DATE_PARSE) &&
        (parse_date(end_date, &end_year,
                    &end_month, &end_day) == GOOD_DATE_PARSE)) {
      if ((start_day < MIN_DAY) || (start_day > MAX_DAY) ||
          (start_month < MIN_MONTH) || (start_month > MAX_MONTH) ||
          (start_year < MIN_YEAR) || (start_year > MAX_YEAR) ||
          (end_day < MIN_DAY) || (end_day > MAX_DAY) ||
          (end_month < MIN_MONTH) || (end_month > MAX_MONTH) ||
          (end_year > MAX_YEAR) || (end_year < MIN_YEAR)) {
        fclose(file);
        file = NULL;
        return BAD_DATA;
      }

      if (((start_year > end_year) || (start_year == end_year)) &&
          ((start_month > end_month) || ((start_year == end_year))) &&
          ((start_month == end_month) && (start_day > end_day))) {
        fclose(file);
        file = NULL;
        return BAD_DATA;
      }
    }
    else {
      fclose(file);
      file = NULL;
      return BAD_DATA;
    }

    strcpy(g_rental_history[count][0], customer_name);
    strcpy(g_rental_history[count][1], start_date);
    strcpy(g_rental_history[count][2], end_date);
    strcpy(g_vehicle_info[count][0], vin);
    strcpy(g_vehicle_info[count][1], make);
    strcpy(g_vehicle_info[count][2], model);
    g_rental_stats[count][0] = miles;
    g_rental_stats[count][1] = rating;
    g_rental_stats[count][2] = customer_fee;
    g_rental_stats[count][3] = maintenance_cost;
    count++;
    has_records = 1;
  }

  fclose(file);
  file = NULL;
  if (!has_records) {
    return NO_DATA_POINTS;
  }
  g_rental_count = count;
  return count;
} /* read_tables() */

/*
 * Gets the total miles from a vehicle's data
 */

float get_total_miles(char *vin) {
  if (g_rental_count == 0) {
    return (float)NO_DATA_POINTS;
  }

  int found = 0;
  float total_miles = 0;

  for (int i = 0; i < g_rental_count; i++) {
    if (strcmp(g_vehicle_info[i][0], vin) == 0) {
      total_miles += g_rental_stats[i][0];
      found = 1;
    }
  }

  return found ? total_miles : (float)NOT_FOUND;
} /* get_total_miles() */

/*
 * Finds the satisfaction of a average
 * customer for the car brand
 */

float avg_brand_satisfaction(char *make) {
  if (g_rental_count == 0) {
    return (float)NO_DATA_POINTS;
  }

  int count = 0;
  float total = 0;

  for (int i = 0; i < g_rental_count; i++) {
    if (strcmp(g_vehicle_info[i][1], make) == 0) {
      total += g_rental_stats[i][1];
      count++;
    }
  }

  return count > 0 ? total / count : (float)NOT_FOUND;
} /* avg_brand_satisfaction() */

/*
 * Finds the average cost of maintenance
 * for the car brand selected.
 */

float avg_maintenance_cost(char *make, char *model) {
  if (g_rental_count == 0) {
    return (float)NO_DATA_POINTS;
  }

  int count = 0;
  float total = 0;

  for (int i = 0; i < g_rental_count; i++) {
    if ((strcmp(g_vehicle_info[i][1], make) == 0) &&
        (strcmp(g_vehicle_info[i][2], model) == 0)) {
      total += g_rental_stats[i][3];
      count++;
    }
  }

  return count > 0 ? total / count : (float)NOT_FOUND;
} /* avg_maintenance_cost() */

/*
 * Knows if the car should or should not be
 * retired based on the car stats.
 */

int retire_vehicles(float miles,
                    char retirable_vehicles[MAX_RENTALS][MAX_BUF_LEN]) {
  if (g_rental_count == 0) return NO_DATA_POINTS;

  int count = 0;

  for (int i = 0; i < g_rental_count; i++) {
    char *vin = g_vehicle_info[i][0];

    int exists = 0;
    for (int j = 0; j < count; j++) {
      if (strcmp(retirable_vehicles[j], vin) == 0) {
        exists = 1;
        break;
      }
    }
    if (exists) continue;

    float total = 0;
    for (int j = 0; j < g_rental_count; j++) {
      if (strcmp(g_vehicle_info[j][0], vin) == 0) {
        total += g_rental_stats[j][0];
      }
    }

    if (total >= miles) {
      strncpy(retirable_vehicles[count], vin, MAX_BUF_LEN);
      count++;
    }
  }

  return count;
} /* retire_vehicles() */

/*
 * Finds the most popular make model from
 * the data provided
 */

int popular_make_model() {
  if (g_rental_count == 0) {
    return NO_DATA_POINTS;
  }

  int count = 0;
  int index = 0;

  for (int i = 0; i < g_rental_count; i++) {
    int current_count = 1;
    for (int j = i + 1; j < g_rental_count; j++) {
      if ((strcmp(g_vehicle_info[i][1], g_vehicle_info[j][1]) == 0) &&
          (strcmp(g_vehicle_info[i][2], g_vehicle_info[j][2]) == 0)) {
        current_count++;
      }
    }

    if (current_count > count) {
      count = current_count;
      index = i;
    }
  }

  return index;
} /* popular_make_model() */

/*
 * See if the user can afford the car
 * and if it is within budget by
 * the data of the car.
 */

float calc_vehicle_profitability(char *vin) {
  if (g_rental_count == 0) {
    return (float)NO_DATA_POINTS;
  }

  int found = 0;
  float total_main = 0;
  float total_fees = 0;

  for (int i = 0; i < g_rental_count; i++) {
    if (strcmp(g_vehicle_info[i][0], vin) == 0) {
      total_fees += g_rental_stats[i][2];
      total_main += g_rental_stats[i][3];
      found = 1;
    }
  }

  if (!found) {
    return (float)NOT_FOUND;
  }
  if (total_fees == 0) {
    return 0;
  }

  float profitability = (1 - (total_main / total_fees)) * 100;
  return profitability < 0 ? 0 : profitability;
} /* calc_vehicle_profitability() */

/*
 * Uses the data provided and creates a output file
 * that will have a report printed onto
 * of it for the customer via the input file's data.
 */

int generate_customer_report(char *out_file, char *customer_name) {
  if (g_rental_count == 0) {
    return NO_DATA_POINTS;
  }

  FILE *file = fopen(out_file, "w");
  if (file == NULL) {
    return FILE_WRITE_ERR;
  }

  int total_rent = 0;
  float total_miles = 0;
  float total_fees = 0;
  int rented_count = 0;
  int rented_index = -1;

  fprintf(file, "Rental History for %s:\n\n", customer_name);

  for (int i = 0; i < g_rental_count; i++) {
    if (strcmp(g_rental_history[i][0], customer_name) == 0) {
      total_rent++;
      total_miles += g_rental_stats[i][0];
      total_fees += g_rental_stats[i][2];

      fprintf(file, "Rental %d:\n", total_rent);
      fprintf(file, "%s to %s\n", g_rental_history[i][1],
              g_rental_history[i][2]);
      fprintf(file, "Vehicle: %s %s - %s\n", g_vehicle_info[i][1],
              g_vehicle_info[i][2], g_vehicle_info[i][0]);
      fprintf(file, "Miles Traveled: %.2f\n", g_rental_stats[i][0]);
      fprintf(file, "Rating: %.2f\n", g_rental_stats[i][1]);
      fprintf(file, "Customer Fee: %.2f\n\n", g_rental_stats[i][2]);

      int current_count = 1;
      for (int j = i + 1; j < g_rental_count; j++) {
        if ((strcmp(g_vehicle_info[i][1], g_vehicle_info[j][1]) == 0) &&
            (strcmp(g_vehicle_info[i][2], g_vehicle_info[j][2]) == 0) &&
            (strcmp(g_rental_history[i][0], g_rental_history[j][0]) == 0)) {
          current_count++;
        }
      }

      if (current_count > rented_count) {
        rented_count = current_count;
        rented_index = i;
      }
    }
  }

  if (total_rent == 0) {
    fclose(file);
    return NOT_FOUND;
  }

  fprintf(file, "Overall Summary:\n");
  fprintf(file, "Total Rentals: %d\n", total_rent);
  fprintf(file, "Total Miles Traveled: %.2f\n", total_miles);
  fprintf(file, "Total Customer Fees: %.2f\n", total_fees);

  if (rented_index != -1) {
    fprintf(file, "Most Commonly Rented Vehicle: %s %s\n",
            g_vehicle_info[rented_index][1],
            g_vehicle_info[rented_index][2]);
  }

  fclose(file);
  return OK;
} /* generate_customer_report() */
