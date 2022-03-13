#include<stdio.h>
#include<string.h>
void main(){
    char str[100];
    printf("Enter a string: ");
    gets(str);
    int i=0;
    while(str[i]!=0){
        if(str[i]==' '){
            if(str[i+1]==' '){
                if(str[i+2]==' '){
                    str[i]='\n';
                    int j=i+1;
                    while(str[j]!=0){
                        str[j] = str[j+2];
                        j++;
                    }
                }
                else{
                    str[i]='\t';
                    int j=i+1;
                    while(str[j]!=0){
                        str[j] = str[j+1];
                        j++;
                    }
                }
            }
            else{
                int len=strlen(str), j=i+1;
                while(len>=j){
                    str[len+1] = str[len];
                    len--;
                }
                str[j]=' ';
                i++;
            }
        }
        i++;
    }
    printf("%s", str);
}