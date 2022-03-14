#include <stdio.h>
void reading(int *mat, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Enter element (%d, %d): ", i + 1, j + 1);
            scanf("%d", mat + i * n + j);
        }
    }
}
void add(int *mat1, int *mat2, int m, int n)
{
    int mat3[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            mat3[i][j] = *(mat1 + i * n + j) + *(mat2 + i * n + j);
            printf("%d ", mat3[i][j]);
        }
        printf("\n");
    }
}
void display(int *mat, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", *(mat + i * n + j));
        }
        printf("\n");
    }
}
void main()
{
    int m, n;
    printf("Enter the order of matrix 1: ");
    scanf("%d %d", &m, &n);
    int mat1[m][n], mat2[m][n];
    printf("Input the elements in the matrix:\n");
    reading(mat1, m, n);
    printf("Input the elements in the matrix 2 to add:\n");
    reading(mat2, m, n);
    printf("Displaying matrix 1:\n");
    display(mat1, m, n);
    printf("Displaying matrix 2:\n");
    display(mat2, m, n);
    printf("Adding above 2 matrices:\n");
    add(mat1, mat2, m, n);
}