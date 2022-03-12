#include<stdio.h>

int main()
{
  int d1,m1,y1,d2,m2,y2,val=0,check;

  printf("Enter first (dd/mm/yyyy) --> ");
  scanf("%d%d%d",&d1,&m1,&y1);
  printf("Enter second (dd/mm/yyyy) --> ");
  scanf("%d%d%d",&d2,&m2,&y2);

  if(y1!=y2)
    val+=((y2-y1)*365);
  if(m1==m2)
    val+=(d2-d1);

  else
  {
    if((m1<=7 && m1%2!=0) || (m1>7 && m1%2==0))
      check=1;
    else if(m1==2) check=2;
    else check=3;

    switch(check){
      case 1 : val+=(31-d1);break;
      case 2 : val+=(28-d1);break;
      case 3 : val+=(30-d1);break;
    }

    for(int i=m1+1;i<m2;i++)
    {
      if((i<=7 && i%2!=0) || (i>7 && i%2==0))
        check=1;
      else if(i==2)
        check=2;
      else check=3;

      switch(check)
      {
        case 1 : val+=31;break;
        case 2 : val+=28;break;
        case 3 : val+=30;break;
      }
    }
  val+=d2;
  }
  printf("Number of days : %d",val);

  return 0;
}
