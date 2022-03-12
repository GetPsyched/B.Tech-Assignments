#include <stdio.h>

int main()
{
  int n;
  printf("Enter day --> ");
  scanf("%d", &n);
  switch (n) {
    case 1: printf("\nIt's January!\n");
            break;
    case 2: printf("\nIt's February!\n");
            break;
    case 3: printf("\nIt's March!\n");
            break;
    case 4: printf("\nIt's April!\n");
            break;
    case 5: printf("\nIt's May!\n");
            break;
    case 6: printf("\nIt's June!\n");
            break;
    case 7: printf("\nIt's July!\n");
            break;
    case 8: printf("\nIt's August!\n");
            break;
    case 9: printf("\nIt's September!\n");
            break;
    case 10: printf("\nIt's October!\n");
            break;
    case 11: printf("\nIt's November!\n");
            break;
    case 12: printf("\nIt's December!\n");
            break;
    default: printf("\nInvalid Input\n");
  }
}
