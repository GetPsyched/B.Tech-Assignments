#include <stdio.h>

int main()
{
  float length;
  printf("Enter length in cm --> ");
  scanf("%f", &length);
  if (1)
  {printf("\nLength in feet is %f feet", length/30.48);
  printf("\nLength in inches is %f inches\n", length/12);}
}
