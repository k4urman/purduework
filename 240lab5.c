#ifndef HW5_H
#define HW5_H

#include <stdio.h>

/* Constant definitions */
#define MAX_NAME_LEN    (20)  /* Max length of any string */
#define FREE_OFFICE     (-10)
#define N_DAYS          (5)
#define N_HOURS         (9)

/* Error codes */
#define OK              (-1)   /* No errors, everything as should be */
#define NO_EMPLOYEE     (-2)
#define NO_OVERLAP      (-3)
#define WRITE_ERR       (-4)
#define NO_OFFICE       (-5)

#define BAD_EMPLOYEE ((employee_t){\
  .id_number = FREE_OFFICE,\
  .first_name = "BOGUS",\
  .last_name = "BOGUS",\
  .title = -1,\
  .salary = -1.0,\
  .schedule[N_DAYS - 1][N_HOURS - 1] = 'A'})

enum title_t {
  TECHNICIAN,
  MANAGER,
  SALESPERSON
};

/* Structure Declarations */
typedef struct {
  int id_number;
  char first_name[MAX_NAME_LEN];
  char last_name[MAX_NAME_LEN];
  enum title_t title;
  float salary;
  char schedule[N_DAYS][N_HOURS];
} employee_t;

/* Function prototypes */
employee_t read_employee(FILE *, int);
int write_employee(FILE *, employee_t, int);
int hire_employee(FILE *, employee_t);
int fire_employee(FILE *, employee_t);
float percent_occupancy(FILE *, float);
float average_salary_by_title(FILE *, enum title_t);
employee_t find_employee_by_id(FILE *, int);
employee_t find_employee_by_name(FILE *, char *, char *);
int give_raise(FILE *, int, float);
int schedule_meeting(FILE *, int, int);

#endif // HW5_H

/* Maninder (Kaurman) Kaur, hw5.c, CS 24000, Spring 2025
 */

/* Add any includes here */

#include "hw5.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * read_employee will read the nth
 * employee's record from the file provided
 * which is opened and read.
 */

employee_t read_employee(FILE *file, int n) {
  assert(file != NULL);
  assert (n >= 0);

  employee_t employee = {
    .id_number = FREE_OFFICE,
    .first_name = "",
    .last_name = "",
    .title = TECHNICIAN,
    .salary = 0.0f,
    .schedule = {
      {'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A'},
      {'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A'},
      {'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A'},
      {'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A'},
      {'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A'}
    }};

  fseek(file, n * sizeof(employee_t), SEEK_SET);
  if (fread(&employee, sizeof(employee_t), 1, file) != 1) {
    return BAD_EMPLOYEE;
  }
  return employee;
} /* read_employee() */

/*
 * write_employee will write in the
 * employee's record at the position n
 */

int write_employee(FILE *file, employee_t employee, int n) {
  assert(file != NULL);
  assert(n >= 0);
  assert(strlen(employee.first_name) < MAX_NAME_LEN);
  assert(strlen(employee.last_name) < MAX_NAME_LEN);
  assert((employee.id_number == FREE_OFFICE) ||
      ((employee.id_number > 0) &&
      (employee.salary > 0) &&
      (employee.title >= TECHNICIAN) &&
      (employee.title <= SALESPERSON)));

  if (employee.id_number != FREE_OFFICE) {
    for (int i = 0; i < N_DAYS; i++) {
      for (int j = 0; j < N_HOURS; j++) {
        assert((employee.schedule[i][j] == 'A') ||
               (employee.schedule[i][j] == 'B'));
      }
    }
  }

  fseek(file, 0, SEEK_END);
  long file_size = ftell(file);
  if (n * sizeof(employee_t) > file_size) {
    return WRITE_ERR;
  }

  fseek(file, n * sizeof(employee_t), SEEK_SET);
  if (fwrite(&employee, sizeof(employee_t), 1, file) != 1) {
    return WRITE_ERR;
  }
  return OK;
} /* write_employee() */

/*
 * hire_employee will take the
 * employee's info from the file
 * and return the available office
 * for the employee to start working at!
 */

int hire_employee(FILE *file, employee_t employee) {
  assert(file != NULL);
  assert(employee.id_number > 0);
  assert(employee.salary > 0);
  assert(strlen(employee.first_name) < MAX_NAME_LEN);
  assert(strlen(employee.last_name) < MAX_NAME_LEN);
  assert((employee.title >= TECHNICIAN) &&
         (employee.title <= SALESPERSON));

  rewind(file);

  employee_t current_employee = {
    .id_number = FREE_OFFICE,
    .first_name = "",
    .last_name = "",
    .title = TECHNICIAN,
    .salary = 0.0f,
    .schedule = {
      {'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A'},
      {'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A'},
      {'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A'},
      {'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A'},
      {'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A'}
    }};
  int office_number = 0;

  while (fread(&current_employee, sizeof(employee_t), 1, file) == 1) {
    if (current_employee.id_number == FREE_OFFICE) {
      fseek(file, -sizeof(employee_t), SEEK_CUR);
      if (write_employee(file, employee, office_number) == OK) {
        return office_number;
      }
      return WRITE_ERR;
    }
    office_number++;
  }
  return NO_OFFICE;
} /* hire_employee() */

/*
 * fire_employee will find the employee's
 * office location from the file and empty
 * the slot fro FREE_OFFICE, in other words
 * laying them off and opening the office for
 * new employees.
 */

int fire_employee(FILE *file, employee_t employee) {
  assert(file != NULL);
  assert(employee.id_number > 0);
  assert(employee.salary > 0);
  assert(strlen(employee.first_name) < MAX_NAME_LEN);
  assert(strlen(employee.last_name) < MAX_NAME_LEN);
  assert((employee.title >= TECHNICIAN) &&
         (employee.title <= SALESPERSON));

  for (int i = 0; i < N_DAYS; i++) {
    for (int j = 0; j < N_HOURS; j++) {
      assert((employee.schedule[i][j] == 'A') ||
             (employee.schedule[i][j] == 'B'));
    }
  }

  rewind(file);

  employee_t current_employee = {
    .id_number = FREE_OFFICE,
    .first_name = "",
    .last_name = "",
    .title = TECHNICIAN,
    .salary = 0.0f,
    .schedule = {
      {'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A'},
      {'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A'},
      {'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A'},
      {'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A'},
      {'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A'}
    }};
  int office_number = 0;

  while (fread(&current_employee, sizeof(employee_t), 1, file) == 1) {
    if ((current_employee.id_number == employee.id_number) &&
        (strcmp(current_employee.first_name, employee.first_name) == 0) &&
        (strcmp(current_employee.last_name, employee.last_name) == 0)) {
      current_employee.id_number = FREE_OFFICE;
      fseek(file, -sizeof(employee_t), SEEK_CUR);
      if (write_employee(file, current_employee, office_number) == OK) {
        return office_number;
      }
      return WRITE_ERR;
    }
    office_number++;
  }
  return NO_EMPLOYEE;
} /* fire_employee() */

/*
 * percent_occupancy will return the percent
 * of offices that are occupied in the office
 * at that given point ALONGSIDE taking a
 * min_salary into account, only returning values
 * that are greater than the float.
 */

float percent_occupancy(FILE *file, float min_salary) {
  assert(file != NULL);
  assert(min_salary >= 0);

  rewind(file);

  employee_t current = {
    .id_number = FREE_OFFICE,
    .first_name = "",
    .last_name = "",
    .title = TECHNICIAN,
    .salary = 0.0f,
    .schedule = {
      {'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A'},
      {'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A'},
      {'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A'},
      {'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A'},
      {'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A'}
    }};
  int total_offices = 0;
  int occupied_offices = 0;

  while (fread(&current, sizeof(employee_t), 1, file) == 1) {
    total_offices++;
    if ((current.id_number != FREE_OFFICE) &&
        (current.salary > min_salary)) {
      occupied_offices++;
    }
  }
  return total_offices > 0 ?
    (float)occupied_offices / total_offices * 100 : 0.0f;
} /* percent_occupancy() */

/*
 * average_salary_by_title as the anme suggests
 * will return the salary of the position from
 * the title if it exists.
 */

float average_salary_by_title(FILE *file, enum title_t title) {
  assert(file != NULL);
  assert((title >= TECHNICIAN) && (title <= SALESPERSON));

  rewind(file);

  employee_t current_employee = {
    .id_number = FREE_OFFICE,
    .first_name = "",
    .last_name = "",
    .title = TECHNICIAN,
    .salary = 0.0f,
    .schedule = {
      {'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A'},
      {'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A'},
      {'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A'},
      {'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A'},
      {'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A'}
    }};
  float total_salary = 0;
  int count = 0;

  while (fread(&current_employee, sizeof(employee_t), 1, file) == 1) {
    if ((current_employee.id_number != FREE_OFFICE) &&
        (current_employee.title == title)) {
      total_salary += current_employee.salary;
      count++;
    }
  }
  return count > 0 ? total_salary / count : NO_EMPLOYEE;
} /* average_salary_by_title() */

/*
 * find_employee_by_id will read the file
 * for the ID of the employee and then find the
 * return the employee values from the ID
 */

employee_t find_employee_by_id(FILE *file, int id) {
  assert(file != NULL);
  assert(id > 0);

  rewind(file);

  employee_t current_employee = {
    .id_number = FREE_OFFICE,
    .first_name = "",
    .last_name = "",
    .title = TECHNICIAN,
    .salary = 0.0f,
    .schedule = {
      {'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A'},
      {'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A'},
      {'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A'},
      {'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A'},
      {'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A'}
    }};

  while (fread(&current_employee, sizeof(employee_t), 1, file) == 1) {
    if (current_employee.id_number == id) {
      return current_employee;
    }
  }
  return BAD_EMPLOYEE;
} /* find_employee_by_id() */

/*
 * find_employee_by_name will search
 * through the file for the name and return
 * the employee's info from the name
 */

employee_t find_employee_by_name(
FILE *file,
char *first_name,
char *last_name) {
  assert(file != NULL);
  assert(first_name != NULL);
  assert(last_name != NULL);
  assert(strlen(first_name) < MAX_NAME_LEN);
  assert(strlen(last_name) < MAX_NAME_LEN);

  rewind(file);

  employee_t current_employee = {
    .id_number = FREE_OFFICE,
    .first_name = "",
    .last_name = "",
    .title = TECHNICIAN,
    .salary = 0.0f,
    .schedule = {
      {'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A'},
      {'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A'},
      {'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A'},
      {'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A'},
      {'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A'}
    }};

  while (fread(&current_employee, sizeof(employee_t), 1, file) == 1) {
    if ((strcmp(current_employee.first_name, first_name) == 0) &&
        (strcmp(current_employee.last_name, last_name) == 0)) {
      return current_employee;
    }
  }
  return BAD_EMPLOYEE;
} /* find_employee_by_name() */

/*
 * give_raise will search the file
 * for the int value that is the employee
 * ID number and apply the logic of the
 * float raise. They can either get the
 * raise or be fired.
 */

int give_raise(FILE *file, int id, float raise) {
  assert(file != NULL);
  assert(id > 0);

  rewind(file);

  employee_t current_employee = {
    .id_number = FREE_OFFICE,
    .first_name = "",
    .last_name = "",
    .title = TECHNICIAN,
    .salary = 0.0f,
    .schedule = {
      {'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A'},
      {'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A'},
      {'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A'},
      {'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A'},
      {'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A'}
    }};
  int office_number = 0;

  while (fread(&current_employee, sizeof(employee_t), 1, file) == 1) {
    if (current_employee.id_number == id) {
      current_employee.salary += raise;

      if (current_employee.salary <= 0) {
        current_employee.id_number = FREE_OFFICE;
        fseek(file, -sizeof(employee_t), SEEK_CUR);
        if (write_employee(file, current_employee, office_number) == OK) {
          return office_number;
        }
        return WRITE_ERR;
      }

      fseek(file, -sizeof(employee_t), SEEK_CUR);
      return write_employee(file, current_employee, office_number);
    }
    office_number++;
  }
  return NO_EMPLOYEE;
} /* give_raise() */

/*
 * schedile_meeting will search through the
 * file for the two IDs of the employees. Once
 * that is found, the system will search for the
 * earliest time and schedule the two for it.
 */

int schedule_meeting(FILE *file, int id1, int id2) {
  assert(file != NULL);
  assert(id1 > 0);
  assert(id2 > 0);

  employee_t employee1 = find_employee_by_id(file, id1);
  employee_t employee2 = find_employee_by_id(file, id2);

  if ((employee1.id_number == FREE_OFFICE) ||
      (employee2.id_number == FREE_OFFICE)) {
    return NO_EMPLOYEE;
  }

  for (int day = 0; day < N_DAYS; day++) {
    for (int hour = 0; hour < N_HOURS; hour++) {
      if ((employee1.schedule[day][hour] == 'A') &&
          (employee2.schedule[day][hour] == 'A')) {
        return day * 100 + (hour + 8);
      }
    }
  }
  return NO_OVERLAP;
} /* schedule_meeting() */

/* Remember, you don't need a main function!
 * it is provided by hw5_main.c or hw5_test.o
 */
