#include<stdio.h>
int main(){
    char str[100];
    printf("Enter a string: ");
    gets(str);
    int i=0, lwr=0, upr=0, digit=0, sym=0;
    while(str[i]!=0){
        if(str[i]>=65 && str[i]<=90)
            upr++;
        else if(str[i]>=97 && str[i]<=122)
            lwr++;
        else if(str[i]>=48 && str[i]<=57)
            digit++;
        else if((str[i]>=33 && str[i]<=47) || (str[i]>=123 && str[i]<=126) || (str[i]>=58 && str[i]<=64) || (str[i]>=91 && str[i]<=96))
            sym++;
        i++;
    }
    if(i<=8){
        printf("String is smaller than 8 characters, Kindly re-enter the string");
        return 0;
    }
    if(lwr>0 && upr>0 && digit>0 && sym>0)
        printf("TRUE");
    else{
        printf("FALSE\nString do not contain(s)-\n");
        if(lwr==0)
            printf("lower character\n");
        if(upr==0)
            printf("upper character\n");
        if(digit==0)
            printf("number\n");
        if(sym==0)
            printf("special character\n");
    }
    return 0;
}