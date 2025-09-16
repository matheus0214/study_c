#include "stdio.h"

/*
	Write a program to print a histogram of the frequencies of different characters in its input.
*/
int main()
{
	int c;
	int amount = 256;
	int frequencies[amount];

	for (int i = 0; i < amount; ++i) {
		frequencies[i] = 0;
	}

	while ((c = getchar()) != EOF) {
		++frequencies[c];
	}
	
	for (int i = 0; i < amount; ++i)
		if (frequencies[i] != 0)
			if (i == '\n')
				printf("newline - %d\n", frequencies[i]);
			else if (i == ' ')
				printf("space - %d\n", frequencies[i]);
			else
				printf("%c - %d\n", i, frequencies[i]);

	return 0;
}