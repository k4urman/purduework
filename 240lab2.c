#ifndef HW2_H
#define HW2_H

/* Constant Definitions */

#define MAX_NAME_SIZE (30)

/* Error Codes */

#define SUCCESS (0)
#define FILE_READ_ERR (-1)
#define FILE_WRITE_ERR (-2)
#define BAD_RECORD (-3)
#define BAD_DATE (-4)
#define NO_DATA (-5)

/* Function Prototypes */

int count_logins(char *input_file, char *lab, int year, int month, int day);
double total_cpu_usage(char *input_file, char *lab, int start_date,
                       int end_date);
double editor_wars(char *input_file);
int blame_the_kids(char *input_file);
double efficiency_score(char *input_file, char *lab);
int generate_report(char *input_file, char *output_file, char *lab,
                    int start_date, int end_date);

#endif // HW2_H


/*
 * Homework 2
 * Maninder (Kaurman) Kaur
 * CS 240, Spring 2025
 * Purdue University
 */

/* Write your code here */

#include "hw2.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * count_logins counts the num of logins in the lab sesh
 */

int count_logins(char *input_file, char *lab, int year, int month, int day) {
  FILE *file = fopen(input_file, "r");
  if (!file) {
    return FILE_READ_ERR;
  }

  char lab_name[MAX_NAME_SIZE] = {MAX_NAME_SIZE};
  char username[MAX_NAME_SIZE] = {MAX_NAME_SIZE};
  char top_program[MAX_NAME_SIZE] = {MAX_NAME_SIZE};
  int record_year = 0;
  int record_month = 0;
  int record_day = 0;
  int procs_run = 0;
  int count = 0;
  double duration = 0.0;
  double cpu = 0.0;

  while (1) {
    int fields_read = fscanf(file,
      "%d-%d-%d,\"%29[^\"]\",%29[^,],%lf,%d,\"%29[^\"]\",%lf",
      &record_year,
      &record_month,
      &record_day,
      lab_name,
      username,
      &duration,
      &procs_run,
      top_program,
      &cpu);

    if (fields_read == EOF) {
      break;
    }

    if (fields_read != 9) {
      fclose(file);
      return BAD_RECORD;
    }

    if ((record_year <= 0) ||
        (record_month < 1) ||
        (record_month > 12) ||
        (record_day < 1) ||
        (record_day > 30)) {
      fclose(file);
      return BAD_DATE;
    }

    if ((year <= 0) ||
        (month < 1) ||
        (month > 12) ||
        (day < 1) ||
        (day > 30)) {
      fclose(file);
      return BAD_DATE;
    }

    if ((duration <= 0) ||
        (procs_run <= 0) ||
        (cpu <= 0)) {
      fclose(file);
      return BAD_RECORD;
    }

    if ((strcmp(lab_name, lab) == 0) &&
        (record_year == year) &&
        (record_month == month) &&
        (record_day == day)) {
      count++;
    }
  }

  fclose(file);

  if (count == 0) {
    return NO_DATA;
  }

  return count;
} /* count_logins() */

/*
 * total_cpu_usage() finds the amount of cpu amount used
 */

double total_cpu_usage(char *input_file,
                       char *lab,
                       int start_date,
                       int end_date) {
  FILE *file = fopen(input_file, "r");
  if (!file) return FILE_READ_ERR;

  char lab_name[MAX_NAME_SIZE] = {MAX_NAME_SIZE};
  char username[MAX_NAME_SIZE] = {MAX_NAME_SIZE};
  char top_program[MAX_NAME_SIZE] = {MAX_NAME_SIZE};
  int record_year = 0;
  int record_month = 0;
  int record_day = 0;
  int procs_run = 0;
  double duration = 0.0;
  double cpu = 0.0;
  double total_cpu = 0.0;
  int date = 0;

  while (1) {
    int fields_read = fscanf(file,
      "%d-%d-%d,\"%29[^\"]\",%29[^,],%lf,%d,\"%29[^\"]\",%lf",
      &record_year, &record_month, &record_day, lab_name, username,
      &duration, &procs_run, top_program, &cpu);

    if (fields_read == EOF) {
      break;
    }

    if (fields_read != 9) {
      fclose(file);
      return BAD_RECORD;
    }

    if ((record_year <= 0) ||
        (record_month < 1) ||
        (record_month > 12) ||
        (record_day < 1) ||
        (record_day > 30)) {
      fclose(file);
      return BAD_DATE;
    }

    if (((start_date / 10000) <= 0) ||
        (((start_date / 100) % 100) < 1) ||
        (((start_date / 100) % 100) > 12) ||
        ((start_date % 100) < 1) ||
        ((start_date % 100) > 30)) {
      fclose(file);
      return BAD_DATE;
    }

    if (((end_date / 10000) <= 0) ||
        (((end_date / 100) % 100) < 1) ||
        (((end_date / 100) % 100) > 12) ||
        ((end_date % 100) < 1) ||
        ((end_date % 100) > 30)) {
      fclose(file);
      return BAD_DATE;
    }

    if ((duration <= 0) ||
        (procs_run <= 0) ||
        (cpu <= 0)) {
      fclose(file);
      return BAD_RECORD;
    }

    date = record_year * 10000 + record_month * 100 + record_day;

    if ((date >= start_date) &&
        (date <= end_date) &&
        (strcmp(lab_name, lab) == 0)) {
      total_cpu += cpu;
    }
  }

  fclose(file);
  if (total_cpu == 0.0) {
    return NO_DATA;
  }
  return total_cpu / 60.0;
} /* total_cpu_usage() */

/*
 * editor_wars finds which editor the user is using
 */

double editor_wars(char *input_file) {
  FILE *file = fopen(input_file, "r");
  if (!file) return FILE_READ_ERR;

  char lab_name[MAX_NAME_SIZE] = {MAX_NAME_SIZE};
  char username[MAX_NAME_SIZE] = {MAX_NAME_SIZE};
  char top_program[MAX_NAME_SIZE] = {MAX_NAME_SIZE};
  int record_year = 0;
  int record_month = 0;
  int record_day = 0;
  int procs_run = 0;
  double duration = 0.0;
  double cpu = 0.0;
  double vi_usage = 0.0;
  double emacs_usage = 0.0;

  while (1) {
    int fields_read = fscanf(file,
      "%d-%d-%d,\"%29[^\"]\",%29[^,],%lf,%d,\"%29[^\"]\",%lf",
      &record_year, &record_month, &record_day, lab_name, username,
      &duration, &procs_run, top_program, &cpu);

    if (fields_read == EOF) {
      break;
    }
    if (fields_read != 9) {
      fclose(file);
      return BAD_RECORD;
    }

    if ((record_year <= 0) ||
        (record_month < 1) ||
        (record_month > 12) ||
        (record_day < 1) ||
        (record_day > 30)) {
      fclose(file);
      return BAD_DATE;
    }

    if ((duration <= 0) ||
        (procs_run <= 0) ||
        (cpu <= 0)) {
      fclose(file);
      return BAD_RECORD;
    }

    if (strstr(top_program, "vi") != NULL) {
      vi_usage += duration / procs_run;
    }
    else if (strstr(top_program, "macs") != NULL) {
      emacs_usage += duration / procs_run;
    }
  }

  fclose(file);

  if ((vi_usage == 0.0) && (emacs_usage == 0.0)) {
    return NO_DATA;
  }

  return vi_usage - emacs_usage;
} /* editor_wars() */

/*
 * blame_the_kids finds who is using the most cpu, which is bad
 */

int blame_the_kids(char *input_file) {
  FILE *file = fopen(input_file, "r");
  if (!file) return FILE_READ_ERR;

  char lab_name[MAX_NAME_SIZE] = {MAX_NAME_SIZE};
  char username[MAX_NAME_SIZE] = {MAX_NAME_SIZE};
  char top_program[MAX_NAME_SIZE] = {MAX_NAME_SIZE};
  char old_username[MAX_NAME_SIZE] = "";
  int record_year = 0;
  int record_month = 0;
  int record_day = 0;
  int procs_run = 0;
  double duration = 0;
  double cpu = 0;
  double max_cpu = 0.0;
  double current_cpu = 0.0;
  int max_line = 0;
  int current_line = 0;
  int first = 0;

  while (1) {
    int fields_read = fscanf(file,
      "%d-%d-%d,\"%29[^\"]\",%29[^,],%lf,%d,\"%29[^\"]\",%lf",
      &record_year, &record_month, &record_day, lab_name, username,
      &duration, &procs_run, top_program, &cpu);

    if (fields_read == EOF) {
      break;
    }

    current_line++;

    if (fields_read != 9) {
      fclose(file);
      return BAD_RECORD;
    }

    if ((record_year <= 0) ||
        (record_month < 1) ||
        (record_month > 12) ||
        (record_day < 1) ||
        (record_day > 30)) {
      fclose(file);
      return BAD_DATE;
    }

    if ((duration <= 0) ||
        (procs_run <= 0) ||
        (cpu <= 0)) {
      fclose(file);
      return BAD_RECORD;
    }

    if (strcmp(username, old_username) == 0) {
      current_cpu += cpu;
    }
    else {
      if ((current_line > 1) &&
          (current_cpu > max_cpu)) {
        max_cpu = current_cpu;
        max_line = first;
      }
      strcpy(old_username, username);
      current_cpu = cpu;
      first = current_line;
    }
  }

  if (current_cpu > max_cpu) {
    max_cpu = current_cpu;
    max_line = first;
  }
  fclose(file);
  if (max_cpu == 0) {
    return NO_DATA;
  }
  if (current_cpu > max_cpu) {
    max_cpu = current_cpu;
    max_line = first;
  }
  return max_line;
} /* blame_the_kids() */

/*
 * efficiency_score sees how efficient the system is
 */

double efficiency_score(char *input_file, char *lab) {
  FILE *file = fopen(input_file, "r");
  if (!file) return FILE_READ_ERR;

  char lab_name[MAX_NAME_SIZE] = {MAX_NAME_SIZE};
  char username[MAX_NAME_SIZE] = {MAX_NAME_SIZE};
  char top_program[MAX_NAME_SIZE] = {MAX_NAME_SIZE};
  int record_year = 0;
  int record_month = 0;
  int record_day = 0;
  int procs_run = 0;
  double duration = 0.0;
  double cpu = 0.0;
  double total_eff = 0.0;
  int count = 0;

  while (1) {
    int fields_read = fscanf(file,
      "%d-%d-%d,\"%29[^\"]\",%29[^,],%lf,%d,\"%29[^\"]\",%lf",
      &record_year, &record_month, &record_day, lab_name, username,
      &duration, &procs_run, top_program, &cpu);

    if (fields_read == EOF) {
      break;
    }
    if (fields_read != 9) {
      fclose(file);
      return BAD_RECORD;
    }

    if ((record_year <= 0) ||
        (record_month < 1) ||
        (record_month > 12) ||
        (record_day < 1) ||
        (record_day > 30)) {
      fclose(file);
      return BAD_DATE;
    }

    if ((duration <= 0) ||
        (procs_run <= 0) ||
        (cpu <= 0)) {
      fclose(file);
      return BAD_RECORD;
    }
    if (strcmp(lab_name, lab) == 0) {
      total_eff += (duration - (procs_run * procs_run)) / cpu;
      count++;
    }
  }
  fclose(file);
  if (count == 0) {
    return NO_DATA;
  }
  return total_eff / count;
} /* efficiency_score() */

/*
 * generate_report just creates a report of the stats above
 */

int generate_report(char *input_file,
                    char *output_file,
                    char *lab,
                    int start_date,
                    int end_date) {
  FILE *input = fopen(input_file, "r");
  if (!input) {
    return FILE_READ_ERR;
  }
  FILE *output = fopen(output_file, "w");
  if (!output) {
    fclose(input);
    return FILE_WRITE_ERR;
  }

  char lab_name[MAX_NAME_SIZE] = {MAX_NAME_SIZE};
  char username[MAX_NAME_SIZE] = {MAX_NAME_SIZE};
  char top_program[MAX_NAME_SIZE] = {MAX_NAME_SIZE};
  int record_year = 0;
  int record_month = 0;
  int record_day = 0;
  int procs_run = 0;
  double duration = 0.0;
  double cpu = 0.0;
  int total_logins = 0;
  int total_procs = 0;
  double total_cpu = 0.0;
  double efficiency = 0.0;
  int date = 0;
  char program_list[10000] = "";

  while (1) {
    int fields_read = fscanf(input,
      "%d-%d-%d,\"%29[^\"]\",%29[^,],%lf,%d,\"%29[^\"]\",%lf",
      &record_year, &record_month, &record_day, lab_name, username,
      &duration, &procs_run, top_program, &cpu);

    if (fields_read == EOF) {
      break;
    }

    if (fields_read != 9) {
      fclose(input);
      fclose(output);
      return BAD_RECORD;
    }

    if ((record_year <= 0) ||
        (record_month < 1) ||
        (record_month > 12) ||
        (record_day < 1) ||
        (record_day > 30)) {
      fclose(input);
      fclose(output);
      return BAD_DATE;
    }

    if (((start_date / 10000) <= 0) ||
        (((start_date / 100) % 100) < 1) ||
        (((start_date / 100) % 100) > 12) ||
        ((start_date % 100) < 1) ||
        ((start_date % 100) > 30)) {
      fclose(input);
      fclose(output);
      return BAD_DATE;
    }

    if (((end_date / 10000) <= 0) ||
        (((end_date / 100) % 100) < 1) ||
        (((end_date / 100) % 100) > 12) ||
        ((end_date % 100) < 1) ||
        ((end_date % 100) > 30)) {
      fclose(input);
      fclose(output);
      return BAD_DATE;
    }

    if ((duration <= 0) ||
        (procs_run <= 0) ||
        (cpu <= 0)) {
      fclose(input);
      fclose(output);
      return BAD_RECORD;
    }

    date = record_year * 10000 + record_month * 100 + record_day;

    if ((strcmp(lab_name, lab) == 0) &&
        (date >= start_date) &&
        (date <= end_date)) {
      total_logins++;
      total_cpu += cpu;
      total_procs += procs_run;
      efficiency += (duration - (procs_run * procs_run)) / cpu;
      strcat(program_list, top_program);
      strcat(program_list, "\n");
    }
  }

  fclose(input);
  if (total_logins == 0) {
    fclose(output);
    return NO_DATA;
  }

  double avg_cpu = total_cpu / total_logins;
  double total_cpu_hours = total_cpu / 60.0;

  fprintf(output, "Lab: %s\n", lab);
  fprintf(output, "Start date: %04d-%02d-%02d\n",
          start_date / 10000,
          (start_date / 100) % 100,
          start_date % 100);
  fprintf(output, "End date: %04d-%02d-%02d\n",
          end_date / 10000,
          (end_date / 100) % 100,
          end_date % 100);
  fprintf(output , "Total logins: %d\n", total_logins);
  fprintf(output, "Total CPU usage (hours): %.2f\n",
          total_cpu_hours);
  fprintf(output, "Average CPU usage per login (minutes): %.2f\n",
          avg_cpu);
  fprintf(output, "Processes executed: %d\n", total_procs);
  fprintf(output, "Efficiency score: %.2f\n",
          efficiency / total_logins);
  fprintf(output, "Programs used:\n%s", program_list);

  fclose(output);
  return SUCCESS;
} /* generate_report() */
