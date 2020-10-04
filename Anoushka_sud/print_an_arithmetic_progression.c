#include<stdio.h>
int main()
{
    int a,d,l;
    printf("enter the first term of the progression:  ");
    scanf("%d",&a);
    printf("enter the common difference:  ");
    scanf("%d",&d);
    printf("enter the last term of the progression:  ");
    scanf("%d",&l);
    printf("%d,",a);
    int x;
    x=a+d;
    printf("%d,",x);
    while(x!=l)
    {x=x+d;
    printf("%d,",x);
    }
    return 0;
}
