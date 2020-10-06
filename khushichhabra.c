#include <stdio.h>
#include <stdlib.h>

int main()
{
   int n,r,s=0;
   printf("enter a numeber:");
   scanf("%d",&n);
   while(n>0)
         {
             r=n%10;
             s=s*10+r;
             n=n/10;
         }
            printf("the reverse :%d",s);

    return 0;
}
