#include <stdio.h>
void prime(int num)
{
    int i = 2;
    while (i < num)
    {
        if (num % i == 0)
        {
            printf("%d is not prime\n", num);
            break;
        }
        else
        {
            i++;
        }
    }
    if (i == num)
    {
        printf("%d is prime\n", num);
    }
}
void primes(int n)
{
    int numb = 2, j = 0, k;
    while (j < n)
    {
        if (numb == 2)
        {
            printf("%d ", numb);
            j++, numb++;
        }
        else
        {
            for (numb = 3; j < n; numb++)
            {
                k = 2;
                while (numb > k)
                {
                    if (numb % k == 0)
                    {
                        break;
                    }
                    else
                    {
                        k++;
                    }
                }
                if (k == numb)
                {
                    printf("%d ", numb);
                    j++;
                }
            }
        }
    }
}
void main()
{
    int num, n;
    printf("Enter a number to find if it is prime or not: ");
    scanf("%d", &num);
    prime(num);
    printf("Enter the value of 'n' to fine first n prime numbers: ");
    scanf("%d", &n);
    primes(n);
}