#include<stdio.h>
void main(){
    char str[100];
    printf("Enter a string: ");
    scanf("%[^\n]s", str);
    int i=0;
    while(str[i]!=0){
        if(str[i]=='a' && str[i+1]=='n' && str[i+2]=='d'){
            int j=i;
            if(str[j+3]==0){
                str[j]=0;
            }
            else{
                while(str[j]!=0){
                    str[j]=str[j+3];
                    j++;
                }
            }
        }
        else{
            i++;
        }
    }
    printf("%s", str);
}