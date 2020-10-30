#include<stdio.h>
int main()
{
    int n;
    printf ("enter number of rows");
    scanf("%d",&n); 

if(n>=1&&n<=10)
{
for(int i=1;i<=n;i++)
{
    
    for(int j=1;j<=i;j++)
    {
        printf("%d ",i);
    }
    printf("\n");
}
}
else
{
     printf("Outside the range");
}


return 0;
}
