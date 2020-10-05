#include <stdio.h>
int main() {

    int a;
    long f=0, s=1,n,count=2;
    scanf("%d", &a);
    if (a > 2) {

        while(count<=a){
        count++;
        n = f + s;
        f = s;
        s = n;
        }
         printf("%d term of fibonacci series is  %d", a,n);   

    }else{
        printf("First two terms are 0, 1 respectively");
    }
    return 0;
}
