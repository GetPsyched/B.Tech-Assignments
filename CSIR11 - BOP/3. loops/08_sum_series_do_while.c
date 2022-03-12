#include <stdio.h>
#include <math.h>

int main()
{
  int n_times, upto_n, s1, s2, s3, s4, s5, s6;
  s1 = s3 = s4 = s6 = 0;
  s2 = s5 = 1;
  printf("Enter times --> ");
  scanf("%d", &n_times);
  printf("Enter upto --> ");
  scanf("%d", &upto_n);
  do
  {
    s1 += n_times;
    s2 += 5 * (n_times - 1);
    s3 += pow(2, n_times);
    n_times--;
  } while (n_times > 0);
  int i = 11;
  do
  { s4 += i; i++; } while (i <= upto_n);
  i = 5;
  do
  { s5 += i; i += 5; } while (i <= upto_n);
  i = 2;
  do
  { s6 += i; i *= 2; } while (i <= upto_n);
  printf("\nS = 1+2+3... N times = %d        S = 11+12+13... upto N = %d", s1, s4);
  printf("\nS = 1+5+10+15... N times = %d    S = 1+5+10+15... upto N = %d", s2, s5);
  printf("\nS = 2+4+8... N times = %d        S = 2+4+8... upto N = %d\n", s3, s6);
}
