#include <stdio.h>

int main ()
{
float a, b, c;
printf ("Delighted to know that you care about your health\n");
printf
  ("This here,is a small initiative to let you know about your BMI value,and hence live a healthier life\n");
printf ("Enter your weight in kg:");
scanf ("%f", &a);
printf ("Enter your hieght in metre:");
scanf ("%f", &b);
c = a / (b * b);
printf ("Your Body Mass Index (BMI) is %f \n", c);
if (c <= 18.5)
{
  printf ("You are underwieght\n");
  printf (">Go nutrient dense\n");
printf (">Eat mini meals through out the day\n");
	  printf (">Go for weightlifting or yoga\n");
    
}
	else
	if (c > 18.5 && c <= 24.9)
	{
	printf ("you are healthy");
	printf ("Congratulations on maintaining a healthy weight\n");
	printf
	("However don't forget to intake plenty of fruits and fluids\n");}
	else if (c>24.9 && c<=29.9)
	{
	    printf("You are overwieght\n");
	    printf(">Include healthy calories in you diet\n");
	    printf(">Make exercise a part of your daily routine\n");
	}
else{
    printf("You are obese\n");
    printf(">Have a cup of green tea every morning morning\n");
    printf(">Have nuts and sprouts instead of fatty snacks\n");
    printf(">Exercise daily\n");
}
printf("Hope so it helped!!\n");
printf("Stay healthy Stay happy :)");
return 0;
}
