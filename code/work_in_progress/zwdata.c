#include <stdio.h>
#include <stdlib.h>

#define	MAXDIGITS   20     /* maximum length zwdata */ 
#define PLUS        1       /* positive sign bit */
#define MINUS       -1      /* negative sign bit */

typedef struct {
    char digits[MAXDIGITS]; /* represent the number */
    int signbit;            /* 1 if positive, -1 if negative */ 
    int length;          /* number of digit in zwdata */
} zwdata;

void print_zwdata(zwdata *n);
void int_to_zwdata(int s, zwdata *n);
void initialize_zwdata(zwdata *n);
int max(int a, int b);
void add_zwdata(zwdata *a, zwdata *b, zwdata *c);
void subtract_zwdata(zwdata *a, zwdata *b, zwdata *c);
int compare_zwdata(zwdata *a, zwdata *b);
void zero_justify(zwdata *n);
void digit_shift(zwdata *n, int d);
void multiply_zwdata(zwdata *a, zwdata *b, zwdata *c);
void divide_zwdata(zwdata *a, zwdata *b, zwdata *c);

void add_zwdata(zwdata *a, zwdata *b, zwdata *c);

void print_zwdata(zwdata *n) {
    int i;

    if (n->signbit == MINUS) {
        printf("- ");
    }

    for (i = n->length; i >= 0; i--) {
        printf("%c",'0'+ n->digits[i]);
    }

    printf("\n");
}

void zero_justify(zwdata *n) {
    while ((n->length > 0) && (n->digits[ n->length ] == 0)) {
        n->length--;
    }

    if ((n->length == 0) && (n->digits[0] == 0)) {
        n->signbit = PLUS;	/* hack to avoid -0 */
    }
}

void int_to_zwdata(int s, zwdata *n) {
    int i;    /* counter */
    int t;    /* int to work with */

    if (s >= 0) {
        n->signbit = PLUS;
    } else {
        n->signbit = MINUS;
    }

    for (i = 0; i < MAXDIGITS; i++) {
        n->digits[i] = (char) 0;
    }

    n->length = -1;

    t = abs(s);

    while (t > 0) {
        n->length ++;
        n->digits[n->length] = (t % 10);
        t = t / 10;
	}

    if (s == 0) {
        n->length = 0;
    }
}

void initialize_zwdata(zwdata *n) {
    int_to_zwdata(0, n);
}

int max(int a, int b) {
    if (a > b) {
        return(a);
    }
    return(b);
}

int compare_zwdata(zwdata *a, zwdata *b) {
    int i;    /* counter */

    if ((a->signbit == MINUS) && (b->signbit == PLUS)) {
        return(PLUS);
    }

    if ((a->signbit == PLUS) && (b->signbit == MINUS)) {
        return(MINUS);
    }

    if (b->length > a->length) {
        return (PLUS * a->signbit);
    }

    if (a->length > b->length) {
        return (MINUS * a->signbit);
    }

    for (i = a->length; i >= 0; i--) {
        if (a->digits[i] > b->digits[i]) {
            return(MINUS * a->signbit);
        }
        if (b->digits[i] > a->digits[i]) {
            return(PLUS * a->signbit);
        }
	}

    return(0);
}

void subtract_zwdata(zwdata *a, zwdata *b, zwdata *c) {
    int borrow;         /* has anything been borrowed? */
    int v;              /* placeholder digit */
    int i;              /* counter */

    initialize_zwdata(c);

    if ((a->signbit == MINUS) || (b->signbit == MINUS)) {
        b->signbit = -1 * b->signbit;
        add_zwdata(a, b, c);
        b->signbit = -1 * b->signbit;
        return;
    }

    if (compare_zwdata(a, b) == PLUS) {
        subtract_zwdata(b, a, c);
        c->signbit = MINUS;
        return;
    }

    c->length = max(a->length, b->length);
    borrow = 0;

    for (i = 0; i <= (c->length); i++) {
        v = (a->digits[i] - borrow - b->digits[i]);
        if (a->digits[i] > 0) {
            borrow = 0;
        }
        if (v < 0) {
            v = v + 10;
            borrow = 1;
        }
        c->digits[i] = (char) v % 10;
    }

    zero_justify(c);
}

/*	c = a +- b;	*/

void add_zwdata(zwdata *a, zwdata *b, zwdata *c) {
    int carry;          /* carry digit */
    int i;              /* counter */

    initialize_zwdata(c);

    if (a->signbit == b->signbit) {
        c->signbit = a->signbit;
    } else {
        if (a->signbit == MINUS) {
            a->signbit = PLUS;
            subtract_zwdata(b, a, c);
            a->signbit = MINUS;
        } else {
            b->signbit = PLUS;
            subtract_zwdata(a, b, c);
            b->signbit = MINUS;
        }
        return;
    }

    c->length = max(a->length, b->length) + 1;
    carry = 0;

    for (i = 0; i <= (c->length); i++) {
        c->digits[i] = (char) (carry + a->digits[i] + b->digits[i]) % 10;
        carry = (carry + a->digits[i] + b->digits[i]) / 10;
    }

    zero_justify(c);
}

/* multiply n by 10^d */

void digit_shift(zwdata *n, int d) {
    int i;    /* counter */

    if ((n->length == 0) && (n->digits[0] == 0)) {
        return;
    }

    for (i = n->length; i >= 0; i--) {
        n->digits[i + d] = n->digits[i];
    }

    for (i = 0; i < d; i++) {
        n->digits[i] = 0;
    }

    n->length = n->length + d;
}

void multiply_zwdata(zwdata *a, zwdata *b, zwdata *c) {
    zwdata row;         /* represent shifted row */
    zwdata tmp;         /* placeholder zwdata */
    int i, j;           /* counters */

    initialize_zwdata(c);

    row = *a;

    for (i = 0; i <= b->length; i++) {
        for (j = 1; j <= b->digits[i]; j++) {
            add_zwdata(c, &row, &tmp);
            *c = tmp;
        }
        digit_shift(&row, 1);
    }

    c->signbit = a->signbit * b->signbit;

    zero_justify(c);
}

void divide_zwdata(zwdata *a, zwdata *b, zwdata *c) {
    zwdata row;                     /* represent shifted row */
    zwdata tmp;                     /* placeholder zwdata */
    int asign, bsign;               /* temporary signs */
    int i;                          /* counters */

    initialize_zwdata(c);

    c->signbit = a->signbit * b->signbit;

    asign = a->signbit;
    bsign = b->signbit;

    a->signbit = PLUS;
    b->signbit = PLUS;

    initialize_zwdata(&row);
    initialize_zwdata(&tmp);

    c->length = a->length;

    for (i = a->length; i >= 0; i--) {
        digit_shift(&row, 1);
        row.digits[0] = a->digits[i];
        c->digits[i] = 0;
        while (compare_zwdata(&row, b) != PLUS) {
            c->digits[i] ++;
            subtract_zwdata(&row, b, &tmp);
            row = tmp;
        }
    }

    zero_justify(c);

    a->signbit = asign;
    b->signbit = bsign;
}

int main(void) {
    int a,b;
    zwdata n1, n2, n3, zero;
    zwdata arr_zwdata[10];

    for (int i=0; i<10; i++) {
        initialize_zwdata(&arr_zwdata[i]);
    }
    
    char command;
    int arg1, arg2, arg3;
    
    while(1) {
        printf("enter command ");
        scanf(" %c",&command);
        if (command == 'Q')
        {
            break;
        }

        printf("enter arg1\n");
        scanf("%d",&arg1);
        printf("enter arg2\n");
        scanf("%d",&arg2);
        printf("enter arg3\n");
        scanf("%d",&arg3);

        switch (command)
        {
        case 'i':
            int_to_zwdata(arg1, &arr_zwdata[arg2]);
            break;

        case 'a':
            add_zwdata(&arr_zwdata[arg1], &arr_zwdata[arg2], &arr_zwdata[arg3]);
            break;
        
        case 's':
            subtract_zwdata(&arr_zwdata[arg1], &arr_zwdata[arg2], &arr_zwdata[arg3]);
            break;
        
        case 'm':
            multiply_zwdata(&arr_zwdata[arg1], &arr_zwdata[arg2], &arr_zwdata[arg3]);
            break;
        
        case 'd':
            divide_zwdata(&arr_zwdata[arg1], &arr_zwdata[arg2], &arr_zwdata[arg3]);
            break;
        
        case 'p':
            print_zwdata(&arr_zwdata[arg1]);

        default:
            break;
        }

        for (int i=0; i<10; i++) {
            printf("arr_zwdata[%d] = ", i);
            print_zwdata(&arr_zwdata[i]);
            printf("\n");
        }
    }
}