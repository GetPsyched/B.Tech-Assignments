#include<stdio.h>
void main(){
    int i, j, m, n;
    printf("Enter the number of rows and columns in the matrix: ");
    scanf("%d %d", &m, &n);
    int arr1[m][n], arr2[n][m];
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            printf("Enter the element (%d, %d): ", i+1, j+1);
            scanf("%d", &arr1[i][j]);
        }
    }
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            arr2[j][i] = arr1[i][j];
        }
    }
    for(j=0; j<n; j++){
        printf("[");
        for(i=0; i<m; i++){
            printf("%3d", arr2[j][i]);
        }
        printf("]\n");
    }
}