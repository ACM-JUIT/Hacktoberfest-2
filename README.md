#include <stdio.h>
int main()
{
    int principleamount,time;
    float rate,simpleinterest;
    scanf("%d",&principleamount);
    scanf("%f",&rate);
    scanf("%d",&time);
    simpleinterest=(principleamount*rate*time)/100;
    printf("%.2f",simpleinterest);
    return 0;
}
