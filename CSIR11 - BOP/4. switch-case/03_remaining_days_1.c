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
    case 1: dd = 31 - dd;
             flag = 1;
             break;
    case 2: dd = 28 - dd;
            flag = 1;
            break;
    case 3: dd = 31 - dd;
            flag = 1;
            break;
    case 4: dd = 30 - dd;
            flag = 1;
            break;
    case 5: dd = 31 - dd;
            flag = 1;
            break;
    case 6: dd = 30 - dd;
            flag = 1;
            break;
    case 7: dd = 31 - dd;
            flag = 1;
            break;
    case 8: dd = 31 - dd;
            flag = 1;
            break;
    case 9: dd = 30 - dd;
            flag = 1;
            break;
    case 10:dd = 31 - dd;
            flag = 1;
            break;
    case 11:dd = 30 - dd;
            flag = 1;
            break;
    case 12:dd = 31 - dd;
            flag = 1;
            break;
    default: printf("\nInvalid Input\n");
  }
  if (flag == 1)
    printf("\nRemaining Days --> %d\n", dd);
}
