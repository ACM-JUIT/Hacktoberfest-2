#include<stdio.h>
int main()
{
int b;
printf("Enter year ");
scanf("%d",&b);
if(b%4==0 || b%400==0)
{
printf("%d is a leap year",b);
}

    else
{
    printf("%d is not a leap year",b);
}
return 0;
}
