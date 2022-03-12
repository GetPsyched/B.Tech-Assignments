#include<stdio.h>

int max_of_array(int array[], int n, int list[])
{
  int large = array[0], pos;
  for (int i=1;i<n;i++)
    if (array[i] > large)
    { large = array[i]; pos = i; }
  list[0] = large;
  list[1] = pos;
}

int main()
{
  int i,n,sum;
  printf("Number of students --> ");
  scanf("%d", &n);
  int roll[n], phy[n], chem[n], math[n];
  for(i=0;i<n;i++)
  {
    printf("\n");
    printf("Enter student %ds Roll Number --> ", i+1);
    scanf("%d", &roll[i]);
    printf("Enter student %ds Physics marks --> ", i+1);
    scanf("%d", &phy[i]);
    printf("Enter student %ds Chemistry marks --> ", i+1);
    scanf("%d", &chem[i]);
    printf("Enter student %ds Maths marks --> ", i+1);
    scanf("%d", &math[i]);
  }
  int list[2], list_same[3];
  printf("\nHighest Marks:\n");
  max_of_array(phy, n, list);
  list_same[0] = list[0];
  printf("\n(i) Roll Number: %d, Marks: %d", roll[list[1]], list[0]);
  max_of_array(chem, n, list);
  list_same[1] = list[0];
  printf("\n(ii) Roll Number: %d, Marks: %d", roll[list[1]], list[0]);
  max_of_array(math, n, list);
  list_same[2] = list[0];
  printf("\n(iii) Roll Number: %d, Marks: %d", roll[list[1]], list[0]);
  if (list_same[0] == list_same[1])
    printf("\nRoll Number: %d has scored highest in multiple subjects\n", list_same[0]);
  else if (list_same[0] == list_same[2])
    printf("\nRoll Number: %d has scored highest in multiple subjects\n", list_same[0]);
  else if (list_same[1] == list_same[2])
    printf("\nRoll Number: %d has scored highest in multiple subjects\n", list_same[1]);
}
