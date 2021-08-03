#pragma once

#define MAXDIGITS 20 /* maximum length zwdata */
#define PLUS 1       /* positive sign bit */
#define MINUS -1     /* negative sign bit */
#define ISSTRING 2   /* istring  sing bit */

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
void add_zwdata(zwdata *a, zwdata *b, zwdata *c);
void subtract_zwdata(zwdata *a, zwdata *b, zwdata *c);
int compare_zwdata(zwdata *a, zwdata *b);
void zero_justify(zwdata *n);
void digit_shift(zwdata *n, int d);
void multiply_zwdata(zwdata *a, zwdata *b, zwdata *c);
void divide_zwdata(zwdata *a, zwdata *b, zwdata *c);
void add_zwdata(zwdata *a, zwdata *b, zwdata *c);
