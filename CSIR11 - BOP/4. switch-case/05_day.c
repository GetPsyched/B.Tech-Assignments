#include <stdio.h>

int main()
{
  int day, month, year, flag = 0;
  printf("Enter day --> ");
  scanf("%d", &day);
  printf("Enter month --> ");
  scanf("%d", &month);
  printf("Enter year --> ");
  scanf("%d", &year);
  int mon, y = year % 100, c = year / 100;

  if(month > 2)
    mon = month;
  else
    mon = (12 + month);

  int w = day + (13*(mon+1))/5 + y + y/4 + c/4 + 5*c;
  w = w % 7;

  switch (w) {
    case 0: printf("\nIt's Saturday!\n");
            break;
    case 1: printf("\nIt's Sunday!\n");
            break;
    case 2: printf("\nIt's Monday!\n");
            break;
    case 3: printf("\nIt's Tuesday!\n");
            break;
    case 4: printf("\nIt's Wednesday!\n");
            break;
    case 5: printf("\nIt's Thursday!\n");
            break;
    case 6: printf("\nIt's Friday!\n");
            break;
    default: printf("\nInvalid Input\n");
  }
}
