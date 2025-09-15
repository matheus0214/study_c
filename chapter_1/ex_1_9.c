#include "stdio.h"

/*
 * Write a program to copy its input to its output, replacing each string of one or
 * more blanks by a single blank.
 */
int main()
{
    int c, prev;

    while((c = getchar()) != EOF) {
        if(c != ' ' && prev != ' ')
            putchar(c);

        if(c == ' ' && prev != ' ')
            putchar(c);

        if(c != ' ' && prev == ' ')
            putchar(c);

        prev = c;
    }

    return 0;
}

/*
 * c = a
 * prev = a
 * print
 *
 * c = ' '
 *
 */
