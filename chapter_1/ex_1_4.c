#include "stdio.h"

/* Write a program to print the corresponding Celsius to Fahrenheit table. */
/* Formula: °F = (°C × 9/5) + 32 */
int main()
{
    float fahr, celsius;
    float lower, upper, step;

    lower = 0;
    upper = 200;
    step = 20;

    celsius = lower;
    while(celsius <= upper) {
        fahr = (celsius * 9.0/5.0) + 32.0;
        printf("%3.0f°C\t%6.1f°F\n", celsius, fahr);
        celsius = celsius + step;
    }

    return 0;
}
