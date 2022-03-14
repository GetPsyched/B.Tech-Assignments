#include <stdio.h>

int main()
{
  int count[4] = {0, 0, 0, 0};
  char s[25];
  printf("Enter a string --> ");
  gets(s);
  for(int i=0; s[i] != '\0'; i++)
  {
    if ((s[i] >= 65 && s[i] <= 90) || (s[i] >= 97 && s[i] <= 122))
      switch (s[i]) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':count[0]++;
                 break;
        default: count[1]++;
      }
    else if (s[i] != ' ')
      switch (s[i]) {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':count[2]++;
                 break;
        default: count[3]++;
      }
  }
  printf("\nNumber of vowels --> %d", count[0]);
  printf("\nNumber of consonants --> %d", count[1]);
  printf("\nNumber of digits --> %d", count[2]);
  printf("\nNumber of other symbols --> %d\n", count[3]);
}
