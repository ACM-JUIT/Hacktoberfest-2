#include <stdio.h>
#include <stdlib.h>

int main()
{
float a,b,res; 
char op;
printf("Enter first number: ");
scanf("%f", &a);
printf("Enter the operation: ");
scanf("%s", &op);
printf("Enter second number: ");
scanf("%f", &b);
switch (op)
{ case '+':
res= a+b;
printf("%f", res);
break;
case '-':
res= a-b;
printf("%f%", res);
break;
case '/' :
res= a/b;
printf("%f", res);
break;
case '*' :
res = a*b;
printf("%f", res);
break;
}
return 0;
}
