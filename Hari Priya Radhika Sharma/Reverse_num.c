//This program is to find the reverse of a number.
#include <stdio.h>
#include <math.h>
int main()
{
    int n, dig, rev= 0, digits = 0, n1;
    scanf("%d", &n); //Enter the number
    n1 = n;
    while (n1 != 0)
    {
        digits++;
        n1 = n1 / 10;
    }
    while (n != 0)
    {

        dig = n % 10;
        rev = rev + (dig * (pow(10, digits - 1)));
        n/=10;
        --digits;
    }
    printf("%d", rev);
    return 0;
}
