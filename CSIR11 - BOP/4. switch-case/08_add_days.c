#include <stdio.h>

int main()
{
  int a, b = 5;
  printf("Enter n --> ");
  scanf("%d", &a);
  switch (a < b) {
    case 1: printf("1");
            break;
    case 0: printf("2");
            break;
  }
}
