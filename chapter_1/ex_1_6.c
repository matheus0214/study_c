#include "stdio.h"

/* Verify that the expression getchar() != EOF is 0 or 1 */
int main()
{
    int c, ev;
    c = getchar();

    printf("Result expression: %d\n", c != EOF);

    return 0;
}
