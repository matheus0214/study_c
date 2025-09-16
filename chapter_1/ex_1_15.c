#include "stdio.h"

#define LOWER 0
#define UPPER 300
#define STEP  20

float fahr_to_celsius(float fahr);

/* Rewrite the temperature conversion program of Section 1.2 to use a function for conversion. */
int main()
{
	float fahr, celsius;

	while (fahr <= UPPER) {
		printf("%.0f\t%.1f\n", fahr, fahr_to_celsius(fahr));
		fahr = fahr + STEP;
	}
}

/* convert Fahrenheit to Celsius temperature */
float fahr_to_celsius(float fahr)
{
	return 5 * (fahr-32) / 9;
}
