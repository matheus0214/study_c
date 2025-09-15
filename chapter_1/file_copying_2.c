#include "stdio.h"

/* copy the input to output; 2st version */
int main()
{
    int c;

    while((c = getchar()) != EOF) {
        putchar(c);
    }

    return 0;
}
