#include <stdio.h>
int main()
 {
   int rows, a, b, number = 0;
   printf("Enter the number of rows: ");
   scanf("%d", &rows);
   for (a = 1; a <= rows; a++)
        {
           for (b = 1; b <= a; ++b)
       {
         printf("%d ", number);
         ++number;
      }
      printf("\n");
   }
   return 0;
}
