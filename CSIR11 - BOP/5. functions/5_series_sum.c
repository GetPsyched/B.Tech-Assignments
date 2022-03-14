#include <stdio.h>
#include <math.h>
int factorial(int a)
{
    if (a == 0 || a == 1)
    {
        return 1;
    }
    else
    {
        return a * factorial(a - 1);
    }
}
float series_sum1(int x, int n)
{
    float sum = 0;
    for (int i = 1; i <= n; i += 2)
    {
        if (i % 4 == 1)
        {
            sum += pow(x, i) / factorial(i);
        }
        else if (i % 4 == 3)
        {
            sum -= pow(x, i) / factorial(i);
        }
    }
    return sum;
}
float series_sum2(int x, int n)
{
    float sum = 0;
    for (int i = 1; i <= n; i += 2)
    {
        float term = 1;
        if (i % 4 == 1)
        {
            int j = i;
            while (j >= 1)
            {
                term *= (float)x / j;
                j--;
            }
            sum += term;
        }
        else if (i % 4 == 3)
        {
            int j = i;
            while (j >= 1)
            {
                term *= (float)x / j;
                j--;
            }
            sum -= term;
        }
    }
    return sum;
}
void main()
{
    int x, n;
    printf("Enter the value of x & n to find sum of series: ");
    scanf("%d %d", &x, &n);
    printf("(i) Sum with use of pow & factorial function: %f\n", series_sum1(x, n));
    printf("(ii) Sum without use of pow & factorial function: %f", series_sum2(x, n));
}