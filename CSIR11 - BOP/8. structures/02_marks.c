#include<stdio.h>

int mark_avg=0;

struct student{
  char name[30];
  int rno;
  int marks;
  int fee;
};

void Topper(struct student st[],int n){
  int max=0;
  for(int i=0;i<n;i++){
    if(st[max].marks<st[i].marks) max=i;
  }
  printf("\nDetails of the topper:\n");
  printf("\nName --> %s", st[max].name);
  printf("\nRoll --> %d", st[max].rno);
  printf("\nMarks --> %d", st[max].marks);
  printf("\nFee --> %d\n", st[max].fee);
}

void greater(struct student st[],int n){
  printf("\nStudents having marks greater than avg marks:\n");
  for(int i=0;i<n;i++){
    if(st[i].marks>mark_avg){
      printf("\nName --> %s", st[i].name);
      printf("\nRoll --> %d", st[i].rno);
      printf("\nMarks --> %d", st[i].marks);
      printf("\nFee --> %d\n", st[i].fee);
    }
  }
}

void FEE(struct student st[],int n){
  int flag = 0;
  printf("\nStudents who have not paid their fees: ");
  for(int i=0;i<n;i++){
    if(st[i].fee<=0){
      flag = 1;
      printf("\nName --> %s", st[i].name);
      printf("\nRoll --> %d", st[i].rno);
      printf("\nMarks --> %d", st[i].marks);
      printf("\nFee --> %d\n", st[i].fee);
    }
  if (flag == 0)
    printf("None");
  }
}

int main(){
  int n;
  printf("Enter the number of students --> ");
  scanf("%d",&n);
  struct student st[n];
  for(int i=0;i<n;i++){
    printf("\nStudent %d:\n",i+1);
    printf("Name --> ");
    scanf("%s", &st[i].name);
    printf("Roll --> ");
    scanf("%d", &st[i].rno);
    printf("Marks --> ");
    scanf("%d", &st[i].marks);
    printf("Fee --> ");
    scanf("%d", &st[i].fee);
    mark_avg+=st[i].marks;
  }
  mark_avg/=n;
  greater(st,n);
  Topper(st,n);
  FEE(st,n);
  return 0;
}
