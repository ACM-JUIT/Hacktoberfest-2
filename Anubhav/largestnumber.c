#include <stdio.h>
int main()
{
    float i,j,k;
    scanf("%f",&i);
    scanf("%f",&j);
    scanf("%f",&k);
    if (i>j){
        printf(" %f is largest number",i);
    }
    else if (j>k){
        printf("%f is largest number",j);
    }

    else{
        printf("Largest number is %.1f",k);
    }
      return 0;
}
