#include <stdio.h>

int main()
{
  int dd, mm, yyyy, flag = 0;
  printf("Enter day --> ");
  scanf("%d", &dd);
  printf("Enter month --> ");
  scanf("%d", &mm);
  printf("Enter year --> ");
  scanf("%d", &yyyy);
  switch (mm) {
    case 2: dd = 28 - dd;
            flag = 1;
            break;
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12: dd = 31 - dd;
             flag = 1;
             break;
    case 4:
    case 6:
    case 9:
    case 11: dd = 30 - dd;
             flag = 1;
             break;
    default: printf("\nInvalid Input\n");
  }
  if (flag == 1)
    printf("\nRemaining Days --> %d\n", dd);
}
