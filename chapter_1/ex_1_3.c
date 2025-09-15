#include "stdio.h"

/* Modify the temperature conversion program to print a heaing above the table */
int main()
{
    printf("Temperature conversion - Fahrenheit to Celsius.\n");
    float fahr, celsius;
    float lower, upper, step;

    lower = 0;
    upper = 300;
    step = 30;

    fahr = lower;
    while(fahr <= upper) {
        celsius = (5.0/9.0) * (fahr-32.0);
        printf("%3.0fF\t%6.1fC\n", fahr, celsius);
        fahr = fahr + step;
    }

    return 0;
}
