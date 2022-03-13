#include <stdio.h>
#include <math.h>
void roots(int a, int b, int c)
{
    int des = b * b - 4 * a * c;
    if (des == 0)
    {
        printf("Nature: REAL & EQUAL\n");
        printf("Roots: %.3f, %.3f", (float)(-1) * b / (2 * a), (float)(-1) * b / (2 * a));
    }
    else if (des > 0)
    {
        printf("Nature: REAL & UNEQUAL\n");
        printf("Roots: %.3f, %.3f", (float)((-1) * b - sqrt(des)) / (2 * a), (float)((-1) * b + sqrt(des)) / (2 * a));
    }
    else
    {
        printf("Nature: COMPLEX & CONJUGATE\n");
        printf("Roots: (%d - %.3fi)/%d, (%d + %.3fi)/%d", -1 * b, sqrt(-1 * des), 2 * a, -1 * b, sqrt(-1 * des), 2 * a);
    }
}
void main()
{
    int a, b, c;
    printf("Enter the coefficient of x^2: ");
    scanf("%d", &a);
    printf("Enter the coefficient of x: ");
    scanf("%d", &b);
    printf("Enter the constant term: ");
    scanf("%d", &c);
    roots(a, b, c);
}