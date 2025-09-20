#include "stdio.h"

#define MAXLINE 1000      /* maximum input line size */

int max;                  /* maximum length seen so far */
char line[MAXLINE];       /* current input line */
char longest[MAXLINE];    /* longest line saved here */

int get_current_line(void);
void copy(void);

/* print longest input line; specialized version */
int main()
{
    int len;
    extern int max;
    extern char longest[];

    max = 0;
    while ((len = get_current_line()) > 0)
        if (len > max) {
            max = len;
            copy();
        }  

    if (max > 0) /* there has a line */
        printf("-> %s", longest);

    return 0;
}

/* get_current_line: specialized version */
int get_current_line()
{
    int c, i;
    extern char line[];

    for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;

    if (c == '\n') {
        line[i] = c;
        ++i;
    }

    line[i] = '\0'; /* add a null char to ensure the line is ending */
    return i; /* if the length is equals 0 this show whe don't had any other line */
}

/* copy: specilized version */
void copy()
{
    int i;
    extern char line[];
    extern char longest[];

    i = 0;
    while ((longest[i] = line[i]) != '\0')
        ++i;
}