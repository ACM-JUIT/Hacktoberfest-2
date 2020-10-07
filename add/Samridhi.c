/*Select one of the items we have to offer and their quantity.
   You get a 10% discount on order above Rs.3500*/

#include <stdio.h>
int main()
{

int a,b,c,d,item_1,item_2,item_3,item_4,Amount;
char ch;
printf(" 1=item_1\n 2=item_2\n 3=item_3\n 4=item_4\n");
printf(" Enter your order \n Please Enter the choice 1,2,3,4\n");
scanf("%d",&ch);
switch(ch)

{
case 1:
printf("Your order is item_1\n");
printf("Please enter your quantity ");

scanf("%d",&a);
Amount=2000*a;

printf("Your total charges is:Rs.%d\n",Amount);
break;
case 2:
printf("Your order is item_2 \n");
printf("Please enter your quantity ");

scanf("%d",&b);
Amount=500*b;

printf("Your total charges is:Rs.%d\n",Amount);
break;
case 3:
printf("Your order is item_3 \n");
printf("Please enter your quantity ");

scanf("%d",&c);
Amount=2500*c;

printf("Your total charges is:Rs.%d\n",Amount);
break;
case 4:
printf("Your order is item_4\n");
printf("Please enter your quantity ");

scanf("%d",&d);
Amount=1500*d;

printf("Your total charges is:Rs.%d\n",Amount);
break;

default:
printf("Invalid choice");

break;
}
if(Amount>3500){
    printf(" Congratulations!! You get 10 percent discount on your order!\n ");
    Amount-=Amount*0.1;
    printf("Charges after discount:Rs.%d",Amount);
}
return 0;
}
