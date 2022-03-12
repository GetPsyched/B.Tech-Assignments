#include<stdio.h>

struct date{
    int d;
    int m;
    int y;
};

struct bank{
  char acc_no[20];
  char name[30];
  int balance;
  int lt_amount;
  struct date lt_date;
};

void find(struct bank b[],int n){
  for(int i=0;i<n;i++){
    if(b[i].acc_no[0]=='1' && b[i].acc_no[1]=='0' && b[i].acc_no[1]=='1')
      printf("%s %s %d %d %d %d %d\n",&b[i].acc_no,&b[i].name,&b[i].balance,&b[i].lt_amount,&b[i],&b[i].lt_date.d,&b[i].lt_date.m,&b[i].lt_date.y);
  }
}

// names of consumers who have not done their transaction during last 1 year
void search(struct bank b[],int n){
  for(int i=0;i<n;i++){
    if(b[i].lt_date.y<=2020)
      printf("%s\n",&b[i].name);
  }
}

int main(){
  int n;
  printf("Enter the number of accounts : ");
  scanf("%d",&n);
  struct bank b[n];
  printf("Enter the details like : acc_no name balance last_amount last_date\n");
  for(int i=0;i<n;i++){
    printf("Book %d : ",i+1);
    scanf("%s%s%d%d%d%d%d",&b[i].acc_no,&b[i].name,&b[i].balance,&b[i].lt_amount,&b[i],&b[i].lt_date.d,&b[i].lt_date.m,&b[i].lt_date.y);
  }
  return 0;
}
