#include "stdio.h"

#define TABSTOP             8
#define LINE_LENGTH_LIMIT   1000000
#define NULL_CHAR           '\0'
#define NEW_LINE            '\n'
#define SPACE               ' '
#define TAB                 '\t'
#define INVALID_LINE        0
#define VALID_LINE          1

int get_current_line(char line[]);
void entab(char line[], int len);
int is_valid_line(char line[], int len);

/*
 * Write a program 'entab' that replaces strings of blank by the minimum number of tabs and blanks
 * to achive the same spacing. Use the same tab stops as for 'detab'.
 * When either a tab or a single blank would suffice to reach a tab stop, which should be given preference?
 */
int main()
{
    char line[LINE_LENGTH_LIMIT];
    int len;

    len = get_current_line(line);
    if (is_valid_line(line, len))
        entab(line, len);
    else
        printf("Not found a valid line\n");

    return 0;
}

void entab(char line[], int len)
{
    int i, spaces, k, copy_all;
    char tmp[len];

    i = 0;
    spaces = 0;
    k = 0;
    copy_all = 0;
    while (copy_all != 1) {
        if (i == len)
            copy_all = 1;

        if (spaces == TABSTOP) {
            // printf("should replace space to tab");
            tmp[k] = TAB;
            spaces = 0;
            ++k;
        }

        // if found a space should count
        if (line[i] == SPACE) {
            ++spaces;
        } else {
            // found a diff character from space
            // if the spaces is gt than 0 should add the spaces, because not reach the tabstop
            if (spaces > 0) {
                for (int s = 0; s < spaces; ++s) {
                    tmp[k] = SPACE;
                    ++k;
                }
            }
            spaces = 0;
            tmp[k] = line[i];

            ++k;
        }


        ++i;
    }

    for (i = 0; i < k; ++i) {
        if (tmp[i] == SPACE) {
            printf(".");
        } else if (tmp[i] == TAB) {
            printf("-");
        } else {
            printf("%c", tmp[i]);
        }
    }
}

int is_valid_line(char line[], int len)
{
    if (len == 0)
        return INVALID_LINE;

    // verify is has a diff character than a space or tabs or just a break line
    int i = 0;
    int found_diff = 0;
    while (i < len && found_diff == 0) {
        if (line[i] != SPACE && line[i] != NEW_LINE && line[i] != TAB)
            found_diff = 1;

        ++i;
    }

    if (found_diff == 1)
        return VALID_LINE;

    return INVALID_LINE;
}

int get_current_line(char line[])
{
    int i, c;

    for (i = 0; i < LINE_LENGTH_LIMIT - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;

    if (c == NEW_LINE) {
        line[i] = NEW_LINE;
        ++i;
    }

    line[i] = NULL_CHAR;

    return i;
}
