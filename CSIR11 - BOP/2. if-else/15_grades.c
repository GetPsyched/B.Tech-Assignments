#include <stdio.h>

int main()
{
  int grade;
  scanf("%d", &grade);
  if (grade >= 90)
    printf("You have achieved A+ Grade!");
  else if (grade >= 80)
    printf("You have achieved A Grade!");
  else if (grade >= 70)
    printf("You have achieved B Grade!");
  else if (grade >= 60)
    printf("You have achieved C Grade!");
  else if (grade >= 50)
    printf("You have achieved D Grade!");
  else if (grade >= 40)
    printf("You have achieved E Grade!");
}
