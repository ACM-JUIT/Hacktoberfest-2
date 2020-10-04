#include <stdio.h>

//                                                               !!! SCHOOL GRADING SYSTEM !!!


int main()
{
    float maths, physics, chem;

    printf("Enter the marks obtained in Maths:\n");
    scanf("%f", &maths);

    printf("Enter the marks obtained in Physics:\n");
    scanf("%f", &physics);

    printf("Enter the marks obtained in Chemistry:\n");
    scanf("%f", &chem);

    float result = (maths + physics + chem) / 300 * 100;
    // to calculate the overall percentage in the end.


  // used if-else conditional statements for each subjects.
    if (maths >= 33)
    {
        printf("You have passed in Maths\n");
    }
    else
    {
        printf("Failed in Maths!!\n");
    }

    if (physics >= 33)
    {
        printf("You have passed in Physics\n");
    }
    else
    {
        printf("Failed in Physics!!\n");
    }
    if (chem >= 33)
    {
        printf("You have passed in Chemistry\n");
    }
    else
    {
        printf("Failed in Chemistry!!\n");
    }

    printf("\nYour overall percentage comes out to be %3.2f\n", result);

    if (result >= 40)
    {
        printf("\nYOU HAVE PASSED! PROMOTED TO THE NEXT CLASS !\n");
    }
    else
    {
        printf("\nYOU HAVE FAILED! HAVE TO REPEAT THE CLASS !\n");
    }

    return 0;
}
