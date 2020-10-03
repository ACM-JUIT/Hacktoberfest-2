#include <stdio.h>

int main()
{
    int n; // hacktoberfest
    float a, b;
    printf("Enter the Operation to be conducted : \n");
    printf("1 for Addition\n");
    printf("2 for Subtraction\n");
    printf("3 for multiplication\n");
    printf("4 for Division\n");
    scanf("%d", &n);

    switch(n)
    {
        case 1 :
        printf("Enter The 2 Numbers for Which Addition is Required\(\Decimal Values Up To 4th Decimal Place\)\: \n");
        scanf("%f%f", &a, &b);
        printf("Addition = %.4f", (a + b));
        break;

        case 2 :
        printf("Enter The 2 Numbers for Which Subtraction is Required\(\Decimal Values Up To 4th Decimal Place\)\: \n");
        scanf("%f%f", &a, &b);
        printf("Subtraction = %.4f", (a - b));
        break;

        case 3 :
        printf("Enter The 2 Numbers for Which Multiplication is Required\(\Decimal Values Up To 4th Decimal Place\)\: \n");
        scanf("%f%f", &a, &b);
        printf("Multiplication = %.4f", (a * b));
        break;

        case 4 :
        printf("Enter The 2 Numbers for Which Division is Required\(\Decimal Values Up To 4th Decimal Place\)\: \n");
        scanf("%f%f", &a, &b);
        printf("Division = %.4f", (a / b));
        break;

        default : printf("The value input is Invalid");
        break;
    }
    return 0;
}
// made by Sanskar Rai
