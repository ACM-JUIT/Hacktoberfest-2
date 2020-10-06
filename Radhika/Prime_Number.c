#include <stdio.h>
 
int main()
{
  int i, Number, Count; 
  
  printf(" Prime Number from 1 to 100 are: \n"); 
  for(Number = 1; Number <= 100; Number++)
  {
    Count = 0;
    for (i = 2; i <= Number/2; i++)
    {
  	if(Number%i == 0)
  	{
     	  Count++;
  	  break;
	}
    }
    if(Count == 0 && Number != 1 )
    {
	printf(" %d ", Number);
    }  
  }
  return 0;
}
