#include <stdio.h>
int maxfn(int a, int b, int c)
{
    if (a >= b && a >= c)
        return a;
    else if (b >= a && b >= c)
        return b;
    else
        return c;
}
void main()
{
    int arr[9], max[3];
    for (int j = 0; j < 9; j++)
    {
        printf("Enter num %d: ", j + 1);
        scanf("%d", &arr[j]);
    }
    for (int j = 0, k = 0; j < 9 && k < 3; j += 3, k++)
        max[k] = maxfn(arr[j], arr[j + 1], arr[j + 2]);
    printf("\nMaximum among those 9 numbers is: %d", maxfn(max[0], max[1], max[2]));
}