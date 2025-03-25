#ifndef HW1_H
#define HW1_H

#define MAX_MESSAGE_LEN 40

#define OK (-1)
#define ERROR (-2)

/*
 * Global variable declarations.
 * You must also define these in your hw1.c file.
 */

extern char g_secret_msg[MAX_MESSAGE_LEN];
extern char g_encoded_msg[MAX_MESSAGE_LEN];
extern char g_cipher_key[MAX_MESSAGE_LEN];

extern int encode_message(int length);
extern int decode_message(int length);
extern int calculate_key(int length);
extern int verify_encoding(int length);

#endif // HW1_H


/*
 * Homework 1
 * Maninder Kaur
 * CS 240, Spring 2025
 * Purdue University
 */

/* Include provided header file which contains declarations for functions and
 * global variables */

#include "hw1.h"
#include <ctype.h>
#include <stdio.h>

char g_secret_msg[MAX_MESSAGE_LEN] = ""; // msg to be encoded
char g_encoded_msg[MAX_MESSAGE_LEN] = ""; // msg to be decoded
char g_cipher_key[MAX_MESSAGE_LEN] = ""; // ciper to do both


/*
 * This function encodes the secret_msg using the cipher_key and length.
 * First, checking to make sure no errors will pop up
 * in regard to the  length or uppercase.
 * Then it will begin the process.
 */

int encode_message(int length) {
  if ((length > MAX_MESSAGE_LEN) || (length <= 0)) {
    return ERROR;
  }
  else {
    for (int i = 0; i < length; i++) {
      if (!isupper(g_cipher_key[i]) ||
        !isupper(g_secret_msg[i])) {
        return ERROR;
      }
      int key_position = g_cipher_key[i] - 'A' + 1;
      g_encoded_msg[i] = (g_secret_msg[i] - 'A' + key_position) % 26 + 'A';
    }
    return OK;
  }
} /* encode_message() */

/*
 * This function edecodes the encoded_msg using the cipher_key and length.
 * First, checking to make sure no errors will pop up
 * in regard to the  length or uppercase.
 * Then it will begin the process.
 */

int decode_message(int length) {
  if ((length > MAX_MESSAGE_LEN) || (length <= 0)) {
    return ERROR;
  }
  else {
    for (int i = 0; i < length; i++) {
      if (!isupper(g_cipher_key[i]) ||
        !isupper(g_encoded_msg[i])) {
        return ERROR;
      }
      int key_position = g_cipher_key[i] - 'A' + 1;
      g_secret_msg[i] = (g_encoded_msg[i] - 'A' - key_position + 26) % 26 + 'A';
    }
    return OK;
  }
} /* decode_message() */

/*
 * This function finds the cipher from length and the msg.
 * First, checking to make sure no errors will pop up
 * in regard to the  length or uppercase.
 * Then it will begin the process.
 */

int calculate_key(int length) {
  if ((length > MAX_MESSAGE_LEN) || (length <= 0)) {
    return ERROR;
  }
  for (int i = 0; i < length; i++) {
    if (!isupper(g_encoded_msg[i]) ||
      !isupper(g_secret_msg[i])) {
      return ERROR;
    }
    int encoded_position = g_encoded_msg[i] - 'A' + 1;
    int secret_position = g_secret_msg[i] - 'A' + 1;
    int key_position = (encoded_position - secret_position + 26) % 26;
    if (key_position == 0) {
      key_position = 26;
    }
    g_cipher_key[i] = 'A' + key_position - 1;
  }
  return OK;
} /* calculate_key() */

/*
 * This verifies is the encoding was correct.
 * First, checking to make sure no errors will pop up
 * in regard to the  length or uppercase.
 * Then it will begin the process.
 */

int verify_encoding(int length) {
  if ((length > MAX_MESSAGE_LEN) || (length <= 0)) {
    return ERROR;
  }
  for (int i = 0; i < length; i++) {
    if (!isupper(g_encoded_msg[i]) ||
      !isupper(g_cipher_key[i]) ||
      !isupper(g_secret_msg[i])) {
      return ERROR;
    }
  }
  for (int i = 0; i < length; i++) {
    int shift_num = g_cipher_key[i] - 'A' + 1;
    char expected = ((g_secret_msg[i] - 'A' + shift_num) % 26) + 'A';
    if (g_encoded_msg[i] != expected) {
      return i;
    }
  }
  return OK;
} /* verify_encoding() */
