#include <stdio.h>

int main()
{
  int min, hr;
  printf("\nEnter hours --> ");
  scanf("%d", &hr);
  printf("Enter minutes --> ");
  scanf("%d", &min);
  if (hr == 24)
    if (min > 9)
      printf("\nThe time is 12:%dam\n", min);
    else
      printf("\nThe time is 12:0%dam\n", min);
  else if (hr == 12)
    if (min > 9)
      printf("\nThe time is 12:%dpm\n", min);
    else
      printf("\nThe time is 12:0%dpm\n", min);
  else if (hr > 12)
    if (min > 9)
      printf("\nThe time is %d:%dpm\n", hr - 12, min);
    else
      printf("\nThe time is %d:0%dpm\n", hr - 12, min);
  else
    if (min > 9)
      printf("\nThe time is %d:%dam\n", hr, min);
    else
      printf("\nThe time is %d:0%dam\n", hr, min);
}
