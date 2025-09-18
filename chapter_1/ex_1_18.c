#include "stdio.h"

#define LINE_LIMIT_LENGTH  1000
#define MAXLINE            10000
#define NULL_CHAR          '\0'
#define NEW_LINE           '\n'
#define TAB                '\t'
#define SPACE              ' '
#define VALID_LINE         1
#define INVALID_LINE       0

int get_oneline(char to[]);
int copy(char line[], char to[], int len, int last_inserted_index);
int is_valid_line(char line[], int len);

/*
	Write a program to remove trailing blanks and tabs from each line of input,
	and do delete entirely blank lines.
*/
int main()
{
	char current_line[LINE_LIMIT_LENGTH];
	char lines_output[MAXLINE];
	int len;
	int last_inserted_index;

	last_inserted_index = 0;
	while ((len = get_oneline(current_line)) > 0) {
		if (is_valid_line(current_line, len) == VALID_LINE) {
			last_inserted_index = copy(current_line, lines_output, len, last_inserted_index);
		}
	}

	printf("\nParsed lines\n");
	for (int i = 0; i < last_inserted_index; ++i) {
		if (lines_output[i] == TAB) {
			printf("\\t");
		} else if (lines_output[i] == SPACE) {
			printf("_");
		} else {
			putchar(lines_output[i]);
		}
	}
	// printf("%s", lines_output);

	return 0;
}

int get_oneline(char to[])
{
	int i, c;

	for (i = 0; i < LINE_LIMIT_LENGTH - 1 && (c = getchar()) != EOF && c != NEW_LINE; ++i)
		to[i] = c;

	if (c == NEW_LINE) {
		to[i] = c; // just add the line ending
		++i;
	}

	to[i] = NULL_CHAR;

	return i;
}

int copy(char line[], char to[], int len, int last_inserted_index)
{
	int start, i, end;
	
	start = 0;
	
	while (line[start] == SPACE || line[start] == TAB)
		++start;
	
	end = len;
	while (line[end] == NEW_LINE || line[end] == TAB || line[end] == SPACE || line[end] == NULL_CHAR)
		--end;

	// printf("(word len: %d) (word end: %d)\n", len, end);
	for (i = start; line[i] != NULL_CHAR && i <= end; ++i) {
		to[last_inserted_index] = line[i];
		++last_inserted_index;
	}

	if (to[last_inserted_index-1] != '\n') {
		to[last_inserted_index] = '\n';
		++last_inserted_index;
	}

	return last_inserted_index;
}

int is_valid_line(char line[], int len) {
	if (len == 0 || line[0] == NEW_LINE) {
		return INVALID_LINE; // not a valid line
	}

	int i;

	i = 0;
	while (line[i] == SPACE || line[i] == NEW_LINE || line[i] == TAB) {
		++i;
	}

	if (i == len) {
		return INVALID_LINE;
	}

	return VALID_LINE; // valid by default
}