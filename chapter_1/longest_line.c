#include "stdio.h"
#define MAXLINE   1000  /* maximum input line length */
#define NULL_CHAR '\0'  /* to mark the end of a string */

int getline_c(char line[], int maxline);
void copy(char to[], char from[]);

/*
	while (there's another line)
		if (it's longer thna the previous longest)
			(save it)
			(save its length)
	print longest line
*/

/* print the longest input line */
int main()
{
	int len;                   /* current line length */
	int max;                   /* maximum length seen so far */
	char line[MAXLINE];        /* current input line */
	char longest[MAXLINE];     /* longest line saved here */

	max = 0;
	while ((len = getline_c(line, MAXLINE)) > 0) {
		if (len > max) {
			max = len;
			copy(longest, line);
		}
	}

	printf("\nLongest line:\n");
	if (max > 0) /* there was a line */
		printf("%s", longest);

	return 0;
}

/* getline_c: read a line into s. return length */
int getline_c(char s[], int lim) 
{
	int c, i;

	for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;

	if (c == '\n') {
		s[i] = c;
		++i;
	}

	s[i] = NULL_CHAR;

	return i;
}

/* copy: copy 'from' into 'to': assume to is big enough */
void copy(char to[], char from[])
{
	int i;

	i = 0;

	while ((to[i] = from[i]) != NULL_CHAR)
		++i;
}