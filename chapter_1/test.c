#include "stdio.h"

int main()
{
    printf("%d %d %d %d\n", '1', '1' - '2', '1' - 9, '1' - '0');
    printf("%d %d %d\n", 'a', 'A', 'a' - 'A');
    printf("%d %d %d\n", '1', '0', '1' - '0');
    printf("%d %d\n", '1', '2' == 49);
    printf("%d\n", 'a' - 12);
    return 0;
}