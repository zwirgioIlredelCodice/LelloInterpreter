#pragma once

#include <stdio.h>

#define MAXDIGITS 20 /* maximum length zwdata */
#define PLUS 1       /* positive sign bit */
#define MINUS -1     /* negative sign bit */
#define ISSTRING 2   /* istring  sing bit */
#define ZWDATA_SIZE sizeof(zwdata)

typedef struct
{
    char digits[MAXDIGITS]; /* represent the number */
    int signbit;            /* 1 if positive, -1 if negative */
    int length;             /* number of digit in zwdata */
} zwdata;

void print_zwdata(zwdata *n);
void int_to_zwdata(int s, zwdata *n);
void initialize_zwdata(zwdata *n);
int max(int a, int b);
void copy_zwdata(zwdata *a, zwdata *b);
int and_zwdata(zwdata *a, zwdata *b);
int or_zwdata(zwdata *a, zwdata *b);
int not_zwdata(zwdata *a);
int equal_zwdata(zwdata *a, zwdata *b);
int notequal_zwdata(zwdata *a, zwdata *b);
int great_zwdata(zwdata *a, zwdata *b);
int less_zwdata(zwdata *a, zwdata *b);
int greatequal_zwdata(zwdata *a, zwdata *b);
int lessequal_zwdata(zwdata *a, zwdata *b);
int get_first_zwdata_digit(zwdata *a);
void add_zwdata(zwdata *a, zwdata *b, zwdata *c);
void subtract_zwdata(zwdata *a, zwdata *b, zwdata *c);
int compare_zwdata(zwdata *a, zwdata *b);
void zero_justify(zwdata *n);
void digit_shift(zwdata *n, int d);
void multiply_zwdata(zwdata *a, zwdata *b, zwdata *c);
void divide_zwdata(zwdata *a, zwdata *b, zwdata *c);
void add_zwdata(zwdata *a, zwdata *b, zwdata *c);
