#include "stdio.h"

/*
 * Write a program to print a histogram of the lengths of words in its input. It is wasy to draw the histogram with bars horizontal;
 * a vertical orientation is more challenging.
*/
int main()
{
	int c, count, i;
	int amounts[100]; /* array to save the words length */

	count = i = 0;
	while ((c = getchar()) != EOF) {
		if ((c == ' '  || c == '\t' || c == '\n') && count > 0) {
			amounts[i] = count;
			++i;
			count = 0;
		} else if (c != ' '  && c != '\t' && c != '\n') {
			// this prevent to count special limiters -> space, tabs and new lines
			++count;
		}
	}

	putchar('\n');

	for (int a = 0; a < i; ++a) {
		for (int k = 0; k < amounts[a]; ++k) {
			putchar('*');
		}
		putchar('\n');
	}

	printf("\n");

	return 0;
}

/*
	⚠️ Points to check or improve

1. Extra empty words
	- If you have multiple spaces in a row, you’ll store empty words (count == 0).
	- Example input: "hi there" → array will contain {2,0,0,5} instead of {2,5}.
	- So your histogram will have blank lines.

2. Last word handling
	- If input ends without a space (e.g., "hello" then EOF), the last word isn’t saved, because you only store amounts[i] when a delimiter is found.
	- This means the final word length might be missing.

3. Array size fixed at 100
	- Works for small input, but if the input has more than 100 words, you’ll write past amounts[99] → undefined behavior.
	- (For the exercise, it’s fine, but it’s a hidden bug).
*/