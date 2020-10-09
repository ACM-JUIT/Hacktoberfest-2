#include<stdio.h>
int main
{
int n,i,s;
scanf("%d",&n);
for(i=1;i<n;i++)
{
if(n%i==0)
s=s+i;
}
if(s==n)
printf("perfect no.");
else
printf("not perfect no.");
}
