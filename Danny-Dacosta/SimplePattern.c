
#include <stdio.h>

int main()
{
    int n,i,j,copy,size,sizecopy;
    scanf("%d",&n);
    copy=n;
    size=n*2-1;
    sizecopy=size;
    int arr[size][size];

    int t1=0,t2=-1;
    for(i=0;i<n;i++)
    {
        for(int t=0;t<sizecopy;t++)arr[t1][++t2]=copy;
        for(int y=0;y<sizecopy-1;y++)arr[++t1][t2]=copy;
        for(int u=0;u<sizecopy-1;u++)arr[t1][--t2]=copy;
        for(int r=0;r<sizecopy-2;r++)arr[--t1][t2]=copy;
        sizecopy-=2;copy--;
    }
    
    for(i=0;i<size;i++)
    {
        for(j=0;j<size;j++)
        printf("%d ",arr[i][j]);
        printf("\n");
        
    }
return 0;
}
