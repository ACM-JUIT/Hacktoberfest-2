#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

int main()
{
 int choice, b = 0;
 cout << "Input 1 for Decimal to Binary Conversion" << endl << "Input 2 for Binary to Decimal Conversion" << endl;
 cin >> choice;

   if(choice == 1)
   {
     int decimal, binary = 0;
     cout << "Enter Decimal: ";
     cin >> decimal;

       while(decimal > 0)
       {
         int i, last_digit, quo;
         last_digit = decimal % 2;
         quo = decimal / 2;
         binary = binary*10 + last_digit;
         decimal = quo;
       }
       cout << binary << " is the Binary." << endl;
   }
   //..........................
   else if(choice == 2)
   { 
     int a;
     cout << "Enter Binary: ";
     cin >> a;
     int j = 0, rem, p;
        while(a > 0)
        {
          rem = a % 10;
          p = a / 10;
          b = b + rem*pow(2, j);
          a = p;
          j++;
        }
        cout << b << " is the Decimal." << endl;
    }
    //..........................
    else
    {
     cout << "not an option" << endl;
    }
    system("pause");
    return 0;
}