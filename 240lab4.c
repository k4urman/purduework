#ifndef HW4_H
#define HW4_H

/* Constant definitions */

#define MAX_MANDELBROT (255)

/* Structure Declarations */

struct complex {
  double x;
  double y;
};

typedef struct complex complex_t;

/* Function Prototypes */

complex_t add_complex(complex_t, complex_t);
complex_t neg_complex(complex_t);
complex_t sub_complex(complex_t, complex_t);
double dot_complex(complex_t, complex_t);
complex_t inv_complex(complex_t);
complex_t mul_complex(complex_t, complex_t);
complex_t div_complex(complex_t, complex_t);
complex_t exp_complex(complex_t);
int mandelbrot(complex_t);

#endif // HW4_H

/*
 * Homework 4
 * Maninder (Kaurman) Kaur
 * CS 240, Spring 2025
 * Purdue University
 */

/* Write your code here */
#include "hw4.h"

#include <math.h>
#include <stdio.h>

/*
 * add_complex adds the fields of the two
 * complexes together and returns the sum.
 */

complex_t add_complex(complex_t a, complex_t b) {
  complex_t result = {0, 0};
  result.x = a.x + b.x;
  result.y = a.y + b.y;
  return result;
} /* add_complex() */

/*
 * neg_complex returns the negative fields
 * of the complexes provided.
 */

complex_t neg_complex(complex_t a) {
  complex_t result = {0, 0};
  result.x = -a.x;
  result.y = -a.y;
  return result;
} /* neg_complex() */

/*
 * sub_complex subtracts the fields of
 * the two complexes and returns the value.
 */

complex_t sub_complex(complex_t a, complex_t b) {
  return add_complex(a, neg_complex(b));
} /* sub_complex() */

/*
 * dot_complex returns the dot product
 * of the two complexes provided.
 */

double dot_complex(complex_t a, complex_t b) {
  return (a.x * b.x) + (a.y * b.y);
} /* dot_complex() */

/*
 * inv_complex returns the reciprocal of
 * the arguments that are provided. We find
 * what to divide by dividing the argument parts
 * by the square of the magnitude of the complex
 * num and negation of the imagnary part.
 */

complex_t inv_complex(complex_t a) {
  double magnitude_squared = dot_complex(a, a);
  complex_t result = {0, 0};
  result.x = a.x / magnitude_squared;
  result.y = -a.y / magnitude_squared;
  return result;
} /* inv_complex() */

/*
 * mul_complex will return the complex product
 * of the two arguments that are passed.
 */

complex_t mul_complex(complex_t a, complex_t b) {
  complex_t result = {0, 0};
  result.x = (a.x * b.x) - (a.y * b.y);
  result.y = (a.x * b.y) + (a.y * b.x);
  return result;
} /* mul_complex() */

/*
 * div_complex returns the complex answer via
 * complex division of the two arguments.
 */

complex_t div_complex(complex_t a, complex_t b) {
  return mul_complex(a, inv_complex(b));
} /* div_complex() */

/*
 * exp_complex returns the complex exponential
 * function e^n when the argument is complex.
 */

complex_t exp_complex(complex_t a) {
  complex_t result = {0, 0};
  double exp_x = exp(a.x);
  result.x = exp_x * cos(a.y);
  result.y = exp_x * sin(a.y);
  return result;
} /* exp_complex() */

/*
 * mandelbrot() is useful for calculating and
 * projecting the mandelbrot set that is used
 * in hw4_view.
 */

int mandelbrot(complex_t c) {
  complex_t z = {0.0, 0.0};
  int iterations = 0;
  while ((dot_complex(z, z) < 4.0) && (iterations < MAX_MANDELBROT)) {
    z = add_complex(mul_complex(z, z), c);
    iterations++;
  }
  return iterations;
} /* mandelbrot() */
