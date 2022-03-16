#include<stdio.h>
void main(){
    int i, j, m, n;
    printf("Enter the number of rows and columns in the matrix: ");
    scanf("%d %d", &m, &n);
    int arr1[50][50];
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            printf("Enter the element (%d, %d): ", i+1, j+1);
            scanf("%d", &arr1[i][j]);
        }
    }
    for(i=0; i<m; i++){
        printf("[");
        for(j=0; j<n; j++){
            printf("%3d", arr1[i][j]);
        }
        printf("]\n");
    }
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            int temp = arr1[i][j];
            arr1[i][j] = arr1[j][i];
            arr1[j][i] = temp;
        }
    }
    if(n>m){
        for(i=0; i<m; i++){
            for(j=0; j<i; j++){
                int temp = arr1[i][j];
                arr1[i][j] = arr1[j][i];
                arr1[j][i] = temp;
            }
        }
    }
    else{
        for(i=0; i<n; i++){
            for(j=0; j<i; j++){
                int temp = arr1[i][j];
                arr1[i][j] = arr1[j][i];
                arr1[j][i] = temp;
            }
        }
    }
    printf("\n");
    for(j=0; j<n; j++){
        printf("[");
        for(i=0; i<m; i++){
            printf("%3d", arr1[j][i]);
        }
        printf("]\n");
    }
}