#include <stdio.h>

int main()
{
  int n;
  printf("Enter day --> ");
  scanf("%d", &n);
  switch (n) {
    case 1: printf("\nIt's Monday!\n");
            break;
    case 2: printf("\nIt's Tuesday!\n");
            break;
    case 3: printf("\nIt's Wednesday!\n");
            break;
    case 4: printf("\nIt's Thursday!\n");
            break;
    case 5: printf("\nIt's Friday!\n");
            break;
    case 6: printf("\nIt's Saturday!\n");
            break;
    case 7: printf("\nIt's Sunday!\n");
            break;
    default: printf("\nInvalid Input\n");
  }
}
