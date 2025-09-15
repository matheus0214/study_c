#include "stdio.h"

/* count lines in input */
int main()
{
    int c, nl;

    nl = 0;
    while((c = getchar()) != EOF)
        if(c == '\n')
            ++nl;

    printf("\nAmount of lines: %d\n", nl);

    return 0;
}
