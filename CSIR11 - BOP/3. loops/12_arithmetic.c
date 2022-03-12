#include <stdio.h>

int main()
{
  float num1, num2;
  char ch, operator;
  do {
    printf("\nEnter first number --> ");
    scanf("%f", &num1);
    printf("Enter second number --> ");
    scanf("%f", &num2);
    printf("Enter operator (+,-,*,/) --> ");
    scanf(" %c", &operator);
    if (operator == '+')
      printf("\nThe sum is --> %f", num1 + num2);
    else if (operator == '-')
      printf("\nThe difference is --> %f", num1 - num2);
    else if (operator == '*')
      printf("\nThe product is --> %f", num1 * num2);
    else if (operator == '/')
      printf("\nThe quotient is --> %f", num1 / num2);
    printf("\n\nDo you want to continue (y/n) --> ");
    scanf(" %c", &ch);
  } while(ch != 'n' && ch != 'N');
}
