#include "stdio.h"

#define MAX_LINE_LENGTH  5 /* Print all input lines longer than MAX_LINE_LENGTH characters (set here to 5 for testing). */
#define MAXLINE          1000
#define NULL_CHAR        '\0'

int my_getline(char to[]);
int append(char from[], char to[], int last_inserted_index, int len_current_word);

/*
	Write a program to print the all input lines that are longer than 80 characters.
*/
int main()
{
	char line[MAXLINE];
	char line_gt_max[MAXLINE];
	int len;
	int last_inserted_index;

	len = 0;
	last_inserted_index = 0;
	while ((len = my_getline(line)) > 0) {
		if (len > MAX_LINE_LENGTH) {
			last_inserted_index = append(line, line_gt_max, last_inserted_index, len);
		}
	}

	printf("\nLines greater than %d characters\n", MAX_LINE_LENGTH);
	printf("%s", line_gt_max);

	return 0;
}

/* 
 * my_getline: read a line of input into 'to' and return its length.
 * - Stops at newline, EOF, or when MAXLINE-1 characters are read.
 * - Appends '\n' if a newline was read.
 * - Always terminates the string with '\0'.
 */

int my_getline(char to[])
{
	int i, c;

	for (i = 0; i < MAXLINE-1 && (c = getchar()) != EOF && c != '\n'; ++i)
		to[i] = c;

	if (c == '\n') {
		to[i] = '\n';
		++i;
	}

	to[i] = NULL_CHAR;
	

	return i;
}

/* 
 * append: copy 'from' into 'to' starting at position 'last_inserted_index'.
 * - Copies exactly 'len_current_word' characters.
 * - Ensures 'to' remains null-terminated after the copy.
 * - Returns the new last_inserted_index (after appended text).
 */
int append(char from[], char to[], int last_inserted_index, int len_current_word)
{
	int i;

	for (i = 0; i < len_current_word; ++i)
		to[i+last_inserted_index] = from[i];
	to[i+last_inserted_index] = NULL_CHAR;

	return last_inserted_index + len_current_word;
}