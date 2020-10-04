#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    int n, m=0,rev=0;
    scanf("%d", &n);
    int old =n;
    for (;n!=0;)
    {
        rev*=10;
        m = n%10;
        n/= 10;
        rev+=m;
        
        //printf("%d", m);
    }
    if(old==rev)
        printf("YES");
    else printf("NO");
    return 0;
}
