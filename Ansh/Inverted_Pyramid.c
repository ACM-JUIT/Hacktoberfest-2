/* This program is written to print an Inverted Pyramid of 'n' rows(n enetred by user), and it will be made of 'c' character (c entered by user)
   Written by Ansh Agrawal
   Date : 29/09/2020
*/
#include<stdio.h>
int main()
{
    int num;
    char ch;
    scanf("%d", &num); // user enter the number of rows he/she wants to print in pyramid
    scanf(" %c", &ch); // user enters the character he/she wants to print in the pyramid
    int i,j,k;
    for(i=num; i>=1; i--)
    {
        for(j=num; j>=i; j--)
            printf(" ");
        for(k=1; k<=i; k++)
        printf("%c ", ch);
        printf("\n");
 
    }
    return 0;
}