#include<iostream>
#include<cstdio>
using namespace std;

//To calculate the cost
int calcCost(int edge[],int N){
 int cost=0;
 for(int i=0;i<N;i++){
  for(int j=i+1;j<N;j++) if(edge[j]<edge[i]) cost++;
 }
 return cost;
}

//to swap the greater value to the end in order to arrange the data
void swap(int edge[],int i,int j){
 int tmp=edge[i];
 edge[i]=edge[j];
 edge[j]=tmp;
}

//Driver code
int main(){
 int N;

 printf("Enter the number of edges : ");
 scanf("%d",&N);

 int edge[N];
 printf("Enter the edges : ");
 for(int i=0;i<N;i++)
   scanf("%d",&edge[i]);

 int bestCost=calcCost(edge,N),newCost,swaps=0;;

 //while loop to check upto when we are not getting the best cost
 while(bestCost>0){
  for(int i=0;i<N-1;i++){
    swap(edge,i,i+1);
    newCost=calcCost(edge,N);
    if(bestCost>newCost){
      printf("After swap %d: \n",++swaps);
      for(int i=0;i<N;i++) printf("%d ",edge[i]);
      printf("\n");
      bestCost=newCost;
    }
   else swap(edge,i,i+1);
  }
 }
 printf("Final Ans\n");
 for(int i=0;i<N;i++)
  printf("%d ",edge[i]);
  printf("\n");

 printf("The peak/Top of the mountain is : %d",edge[N-1]);
 return 0;
}