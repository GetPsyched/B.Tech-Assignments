#include <stdio.h>

int main()
{
  int days, months = 0, years;
  int leap_year = 0;
  printf("\nEnter number of days --> ");
  scanf("%d", &days);
  years = days/365;
  days = days - 365*years - years/4;
  if (days >= 31)
  { months = 1; days -= 31; } // January
  if (days >= 29 && years % 3 == 0 && years != 0)
  { months = 2; days -= 29; } // February leap year
  else if (days >= 28)
  { months = 2; days -= 28; } // February non-leap year
  if (days >= 31)
  { months = 3; days -= 31; } // March
  if (days >= 30)
  { months = 4; days -= 30; } // April
  if (days >= 31)
  { months = 5; days -= 31; } // May
  if (days >= 30)
  { months = 6; days -= 30; } // June
  if (days >= 31)
  { months = 7; days -= 31; } // July
  if (days >= 31)
  { months = 8; days -= 31; } // August
  if (days >= 30)
  { months = 9; days -= 30; } // September
  if (days >= 31)
  { months = 10; days -= 31; } // October
  if (days >= 30)
  { months = 11; days -= 30; } // November
  if (days < 0)
  { years -= 1, months = 11; days += 31; } // Removing extra days for leap year

  printf("\n%d year/s, %d month/s and %d day/s\n", years, months, days);

}
