#include "stdio.h"

#define BACKSLASH 92 /* backslash unicode */

/*
 * Write  program to copy its input to its output, replacing each tab by \t,
 * each backspace by \b, and each backslash by \\. This makes tabs and backspaces
 * visible in an unambiguous way.
 */
int main()
{
    int c, show;

    while((c = getchar()) != EOF) {
        if(c == '\t') {
            printf("\\t");
            show = -1;
        }

        if(c == ' ') {
            printf("\\b");
            show = -1;
        }

        if(c == BACKSLASH) {
            printf("\\\\");
            show = -1;
        }

        if(show != -1) {
            putchar(c);
        }

        show = 1;
    }

    return 0;
}
