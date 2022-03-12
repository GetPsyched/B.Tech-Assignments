#include <stdio.h>
#include <math.h>

int main()
{
  int a, b, c, discriminant;
  printf("\nEnter first number --> ");
  scanf("%d", &a);
  printf("Enter second number --> ");
  scanf("%d", &b);
  printf("Enter third number --> ");
  scanf("%d", &c);
  discriminant = (pow(b, 2) - (4*a*c));
  if (discriminant >= 0)
    printf("The roots are %f and %f", (-b-sqrt(discriminant))/(2*a), (-b+sqrt(discriminant))/(2*a));
  else
    printf("The roots are %f+i%f and %f-i%f", -b/(2*a), -sqrt(-discriminant)/(2*a), -b/(2*a), sqrt(-discriminant)/(2*a));
}
