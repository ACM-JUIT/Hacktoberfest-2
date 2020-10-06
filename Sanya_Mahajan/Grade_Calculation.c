#include<stdio.h>
main()
{
    int marks;
    char name[50];
    printf("Enter name of the student=");
    scanf("%[^\n]%*c",&name);
    printf("\nEnter average marks of student=");
    scanf("%d",&marks);

    if(marks>=80)
    {
        printf("\nGrade : Distinction");
        printf("\nStudent name : %s",name);
    }



    if(marks>=60&&marks<80)
    {
        printf("Grade : 1st Division");
        printf("\nStudent name : %s",name);
    }


    if(marks>=45&&marks<60)
    {
        printf("Grade : 2nd Division");
        printf("\nStudent name : %s",name);
    }


    if(marks>=40&&marks<45)
    {
        printf("Grade : Pass");
        printf("\nStudent name : %s",name);
    }


    if(marks<40)
       {
        printf("Grade : Fail");
        printf("\nStudent name : %s",name);
       }


}
