#include<stdio.h>
void main(){
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);
    int arr[3][n], i, j;
    for(i=0; i<3; i++){
        for(j=0; j<n; j++){
            if(i==0){
                printf("Enter Physics marks for roll no %d: ", j+1);
                scanf("%d", &arr[i][j]);
            }
            else if(i==1){
                printf("Enter Chemistry marks for roll no %d: ", j+1);
                scanf("%d", &arr[i][j]);
            }
            else{
                printf("Enter Maths marks for roll no %d: ", j+1);
                scanf("%d", &arr[i][j]);
            }
        }
    }
    float avgtotal=0;
    for(i=0; i<3; i++){
        float avg=0;
        for(j=0; j<n; j++){
            avg += (float)arr[i][j]/n;
            avgtotal += (float)arr[i][j]/n;
        }
        if(i==0){
            printf("Average marks in Physics: %f\n", avg);
        }
        else if(i==1){
            printf("Average marks in Chemistry: %f\n", avg);
        }
        else{
            printf("Average marks in Maths: %f\n", avg);
        }
    }
    printf("Average marks of whole class: %f", avgtotal);
}