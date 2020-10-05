#include <stdio.h>

int main()
{
    float celsius, fahrenheit;

    printf("ENTER TEMP. IN CELSIUS: ");
    scanf("%f", &celsius);

    fahrenheit = 32+(9 / 5 * celsius);

    printf("%.1f Celsius = %.1f Fahrenheit", celsius, fahrenheit);

    return 0;
}
