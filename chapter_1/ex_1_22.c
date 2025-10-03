#include "stdio.h"

#define MAXLINE_LENGTH          1000
#define MAXLINE_LINES_LENGTH    100000
#define NEWLINE                 '\n'
#define NULLCHAR                '\0'
#define MAXLINE_CHAR            10
#define TAB                     '\t'
#define SPACE                   ' '

int get_current_line(char line[]);
void fold(char line[], int len, char to[]);
/*
 * Write a program to 'fold' long input lines into two or more shorter lines after the last non-blank character
 * that occurs before the n-th  column of input. Make sure your program does something intelligent with very long lines,
 * and if there are no blanks or tabs before the specified column.
 */
int main()
{
    char line[MAXLINE_LENGTH];
    char lines[MAXLINE_LINES_LENGTH];
    int len = 0;

    while ((len = get_current_line(line)) > 0) {
        fold(line, len, lines);
        printf("%s", lines);
    }

    return 0;
}

void fold(char line[], int len, char to[])
{
    int i, break_at, next_break, i_tmp;
    char tmp[MAXLINE_LENGTH];

    i = 0;
    i_tmp = 0;
    break_at = MAXLINE_CHAR;
    next_break = MAXLINE_CHAR;
    while(i < len) {
        // printf("copy %d %d\n", i, break_at);
        if (i == break_at) {
            // printf("Break: %d %d\n", i, break_at);
            if (line[i] == SPACE) {
                tmp[i_tmp] = NEWLINE;
            } else {
                tmp[i_tmp] = NEWLINE;
                if (line[i] != TAB) {
                    tmp[i_tmp+1] = line[i];
                    ++i_tmp;
                }
            }
            next_break = next_break + MAXLINE_CHAR;
            break_at = next_break;
            ++i_tmp;
        } else {
            tmp[i_tmp] = line[i];
            ++i_tmp;
        }

        // input's
        // the quick brown fox
        // HelloWorldFooBarBaz
        // Name:    John    Doe
        // One two three four five six seven
        // supercalifragilisticexpialidocious
        if (line[i] == SPACE) {
            // printf("find space: i(%d) characther(%c)\n", i, line[i]);
            // printf("break at(%d)\n", break_at);
            if (line[next_break] != SPACE && line[next_break] != TAB && next_break < len) {
                // printf("-> next break(%d)\n", next_break);
                int k = next_break;
                int stop = 0;

                while (stop != 1) {
                    if (k > i && line[k] == SPACE) { // found should break
                        break_at = k;
                        stop = 1;
                    }

                    --k;
                }

                // printf("Break: %d\n", break_at);
            }
        }

        ++i;
    }

    printf("\nOUTPUT\n");
    printf("%s\n", tmp);
}

int get_current_line(char line[])
{
    printf("Input: ");
    int i, c;

    for (i = 0; i < MAXLINE_LENGTH - 1 && (c = getchar()) != EOF && c != NEWLINE; ++i)
        line[i] = c;

    if (c == NEWLINE) {
        line[i] = NEWLINE;
        ++i;
    }

    line[i] = NULLCHAR;

    return i;
}
