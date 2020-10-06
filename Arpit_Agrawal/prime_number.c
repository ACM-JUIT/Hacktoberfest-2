#include <stdio.h>

int main() {
   int a,b, i, flag;
   
   printf("Enter two numbers(intervals): ");
   
   scanf("%d %d", &a, &b);
   
   printf("Prime numbers between %d and %d are: ", a, b);

   // iteration until low is not equal to high
   while (a < b) {
      flag = 0;

      // ignore numbers less than 2
      if (a <= 1) {
         ++a;
         continue;
      }

      // if low is a non-prime number, flag will be 1
      for (i = 2; i <= a / 2; ++i) {

         if (a % i == 0) {
            flag = 1;
            break;
         }
      }

      if (flag == 0)
         printf("%d ", a);

      // to check prime for the next number
      // increase low by 1
      ++a;
   }

   return 0;
}
