#include "stdio.h"

#define BREAK   1
#define NOBREAK 0

/* Write a program the prints its input one word per line */
int main()
{
    int c, b, p;

    p = NOBREAK;
    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\t' || c == '\n')
            b = BREAK;
        else
            b = NOBREAK;

        if (b == BREAK && p == NOBREAK)
        {
            putchar('\n');
            p = BREAK;
        }
        else if (p == BREAK && b == NOBREAK)
            p = NOBREAK;

        if (b == NOBREAK && p == NOBREAK)
            putchar(c);
    }

    return 0;
}

/*
 * a_    -> a BREAK
 * a__a  -> a BREAK BREAK a
 * a___a -> a BREAK BREAK BREAK a
 *       a b = NOBREAK p = NOBREAK
 *       _ b = BREAK   p = NOBREAK
 *       _ b = BREAK   p = BREAK
 *       _ b = BREAK   p = BREAK
 *       a b = NOBREAK p = NOBREAK
 * */
