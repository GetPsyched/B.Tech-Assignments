#include <stdio.h>

int main()
{
  float principal, rate, time;
  printf("\nEnter principal amount --> ");
  scanf("%f", &principal);
  printf("Enter interest rate --> ");
  scanf("%f", &rate);
  printf("Enter time (years) --> ");
  scanf("%f", &time);
  printf("\nAmount --> %f\n", principal + (principal * rate * time)/100);
}
