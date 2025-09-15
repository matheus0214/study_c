#include "stdio.h"

/* Write a program to count blank, tabs, and newlines. */
int main()
{
    int c, nl, bl, tb;

    nl = 0;
    bl = 0;
    tb = 0;

    while((c = getchar()) != EOF) {
        if(c == '\n')
            ++nl;
        if(c == '\t')
            ++tb;
        if(c == ' ')
            ++bl;
    }

    printf("\nNew lines: %d\n", nl);
    printf("Blanks: %d\n", bl);
    printf("Tabs: %d\n", tb);

    return 0;
}
