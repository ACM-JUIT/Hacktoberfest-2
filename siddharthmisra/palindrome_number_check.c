#include<stdio.h>

int main()
{
    int n,a,b=0,c,temp;
    scanf("%d",&n);
    temp=n;
    while(n>0){
        a=n%10;
        b=b*10+a;
        c=n/10;
        n=c;

    }
    n=temp;
  if(n==b){
    printf("YES");}
    else{
        printf("NO");
    }
  }
