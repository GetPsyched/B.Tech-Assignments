#include <stdio.h>

int main()
{
  int n;
  printf("Enter n --> ");
  scanf("%d", &n);
  for ( ; n > 0 ; n--)
    printf("Hello\n");
    int n_times, upto_n, s1, s2, s3, s4, s5, s6;
    s1 = s3 = s4 = s6 = 0;
    s2 = s5 = 1;
    printf("Enter times --> ");
    scanf("%d", &n_times);
    printf("Enter upto --> ");
    scanf("%d", &upto_n);
    for ( ; n_times > 0 ; n_times--)
    {
      s1 += n_times;
      s2 += 5 * (n_times - 1);
      s3 += pow(2, n_times);
    }
    for (int i = 11; i <= upto_n; i++)
      s4 += i;
    for (int i = 5; i <= upto_n; i += 5)
      s5 += i;
    for (int i = 2; i <= upto_n; i *= 2)
      s6 += i;
    printf("\nS = 1+2+3... N times = %d        S = 11+12+13... upto N = %d", s1, s4);
    printf("\nS = 1+5+10+15... N times = %d    S = 1+5+10+15... upto N = %d", s2, s5);
    printf("\nS = 2+4+8... N times = %d        S = 2+4+8... upto N = %d\n", s3, s6);
}
