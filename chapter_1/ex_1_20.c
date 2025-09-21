#include "stdio.h"

#define N                4     /* the amount spaces the one tab should had*/
#define MAXLINE_LENGTH   10000
#define NULL_CHAR        '\0'
#define NEW_LINE         '\n'
#define TAB              '\t'
#define SPACE            ' '

int get_current_line(char line[]);
void convert_tabs_to_spaces(char line[], int len);
/*
    Write a program 'detab' that replaces tabs in the input with the proper number os blanks to space
    to the next tabs stop. Assume a fixed set of tab stops, say every 'n' columns. Should 'n' be a 
    variable or a symbolic parameter?
    E.g. convert the tabs to spaces to hit the next tab spot
        -> tabs:____
        -> conv:_ _ _ _
*/

int main()
{
    char current_line[MAXLINE_LENGTH];
    int len;

    len = get_current_line(current_line);
    convert_tabs_to_spaces(current_line, len);

    return 0;
}

int get_current_line(char line[])
{
    int i, c;

    for (i = 0; i < MAXLINE_LENGTH-1 && (c = getchar()) != EOF && c != NEW_LINE; ++i)
        line[i] = c;

    if (c == NEW_LINE) {
        line[i] = c;
        ++i;
    }

    line[i] = NULL_CHAR;

    return i;
}

void convert_tabs_to_spaces(char line[], int len)
{
    char tmp[MAXLINE_LENGTH];
    int copy_all, i, copy_i, k, before_char;

    copy_all = 0; /* false by default*/
    i = 0;
    copy_i = 0;
    before_char = 0;
    while (copy_all == 0) {
        if (i == len)
            copy_all = 1;

        if (line[i] == TAB) { // need to be converted to spaces
            // amount of letters before tab - N
            // printf("Next: %d %d\n", next_tab_spot, before_char);
            for (k = 0; k < N - before_char; ++k) { // this will run 4 times
                tmp[copy_i] = SPACE;
                ++copy_i;
            }

            before_char = 0;
        } else {
            tmp[copy_i] = line[i];
            ++copy_i;

            ++before_char;
        }

        if (before_char == N) {
            before_char = 0;
        }

        ++i;
    }

    printf("Original:\n");
    for(int s = 0; line[s] != NULL_CHAR; ++s) {
        if (line[s] == TAB) {
            printf("\\t");
        } else if (line[s] == SPACE) {
            printf("_");
        } else {
            printf("%c", line[s]);
        }
    }

    for(int s = 0; tmp[s] != NULL_CHAR; ++s) {
        if (tmp[s] == TAB) {
            printf("\t");
        } else if (tmp[s] == SPACE) {
            printf("_");
        } else {
            printf("%c", tmp[s]);
        }
    }
}
