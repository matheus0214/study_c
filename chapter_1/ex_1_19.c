#include "stdio.h"

#define LIMIT_LINE_LENGTH   1000
#define VALID_LINE          1
#define INVALID_LINE        0
#define NULL_CHAR          '\0'
#define NEW_LINE           '\n'
#define TAB                '\t'
#define SPACE              ' '

int get_current_line(char line[]);
int is_valid_line(char line[], int len);
void reverse(char string[]);
/*
	Write a function reverse(s) that reverses the character string s.
	Use it to write a program the reverses its input a line at a time.
*/
int main()
{
	int len;
	char line[LIMIT_LINE_LENGTH];

	while ((len = get_current_line(line)) > 0) {
		if (is_valid_line(line, len)) {
			reverse(line);
			printf("->%s\n", line);
		}
	}

	return 0;
}

void reverse(char string[])
{
	int length;

	for (length = 0; string[length] != '\0' ; ++length)
		;

	char tmp[length];
	int k;
	int len_copy;

	k = 0;
	len_copy = length;
	// printf("Word length: %d\n", length);
	while (length >= 0) {
		if (string[length] != '\0' && string[length] != 10) {
			// printf("Index: %d adding: %d\n", k, string[length]);
			tmp[k] = string[length];
			++k;
		}
		--length;
	}

	int i;
	for (i = 0; i < len_copy; ++i) {
		// printf("tmp %c\n", tmp[i]);
		if (i < k) {
			string[i] = tmp[i];
		} else {
			string[i] = 0;
		}
	}
}

int get_current_line(char line[])
{
	int i, c;

	for (i = 0; i < LIMIT_LINE_LENGTH && (c = getchar()) != EOF && c != '\n'; ++i)
		line[i] = c;

	if (c == '\n') {
		line[i] = c;
		++i;
	}

	line[i] = '\0';

	return i;
}

int is_valid_line(char line[], int len) {
	if (len == 0 || line[0] == NEW_LINE) {
		return INVALID_LINE;
	}

	int i;

	i = 0;
	while (line[i] == SPACE || line[i] == NEW_LINE || line[i] == TAB) {
		++i;
	}

	if (i == len) {
		return INVALID_LINE;
	}

	return VALID_LINE;
}