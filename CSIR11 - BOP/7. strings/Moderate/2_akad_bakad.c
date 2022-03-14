#include<stdio.h>
#include<string.h>
void main(){
    char str[100], sub[50], add[50];
    printf("Enter a string: ");
    scanf("%[^\n]s", str);
    fflush(stdin);
    printf("Enter the substring: ");
    scanf("%[^\n]s", sub);
    fflush(stdin);
    printf("Enter the addition: ");
    scanf("%[^\n]s", add);
    char *pstr = strstr(str, sub), *ptr=str;
    if(pstr){
        int sublen = strlen(sub), addlen = strlen(add), lenstr = strlen(str), k = 0, index = (int)pstr - (int)ptr;
        while(lenstr-k>=index+sublen){
            str[lenstr+addlen-k] = str[lenstr-k];
            k++;
        }
        k=0;
        while(add[k]!=0){
            str[index+sublen+k] = add[k];
            k++;
        }
    }
    printf("%s", str);
}