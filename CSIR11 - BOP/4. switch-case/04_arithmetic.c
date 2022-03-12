#include <stdio.h>

int main()
{
  float num1, num2, product;
  int ch = 2, flag = 0;
  char operator;
  do {
    if (flag == 1)
    {
      printf("\n1. Continue with this result");
      printf("\n2. Start fresh");
      printf("\n3. Exit");
      printf("\n\nEnter your choice --> ");
      scanf("%d", &ch);
      if (ch == 3) break;
    }
    flag = 1;
    if (ch == 2)
    {
      printf("\nEnter first number --> ");
      scanf("%f", &num1);
    }
    else
      num1 = product;
    printf("Enter second number --> ");
    scanf("%f", &num2);
    printf("Enter operator (+,-,*,/) --> ");
    scanf(" %c", &operator);
    switch (operator)
    {
      case '+': product = num1 + num2;
                printf("\nThe sum is --> %f\n", product);
                break;
      case '-': product = num1 - num2;
                printf("\nThe difference is --> %f\n", product);
                break;
      case '*': product = num1 * num2;
                printf("\nThe product is --> %f\n", product);
                break;
      case '/': product = num1 / num2;
                printf("\nThe quotient is --> %f\n", product);
                break;
    }
  } while(ch != 3);
}
