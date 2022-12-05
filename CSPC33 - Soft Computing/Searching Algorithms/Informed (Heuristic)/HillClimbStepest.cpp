#include<iostream>
using namespace std;

const char UP ='1';
const char DOWN= '2';
const char LEFT= '3';
const char RIGHT= '4';


void printArray(int** array)
{
    for(int a=0;a<3;a++)
    {
        for(int b=0;b<3;b++)
        {
            cout<<*(*(array+a)+b)<<"\t";
        }
        cout<<endl;
    }
    cout<<endl;
}
int manhattan(int** ini,int** fin)
{
    int manhattan=0;
    for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(*(*(ini+i)+j)>0)
                {
                    for(int k=0;k<3;k++)
                    {
                        for(int l=0;l<3;l++)
                        {
                            if (*(*(fin+k)+l)==*(*(ini+i)+j))
                            {
                                manhattan=manhattan + (abs(i-k)+abs(j-l));

                            }
                        }
                    }
                }
            }
        }
return manhattan;


}

void makeMove(int** temp,int move)
{
    int flag=0;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(*(*(temp+i)+j)==-1)
            {
                if(move==1)
                {
                    *(*(temp+i)+j)=*(*(temp+(i-1))+j);
                    *(*(temp+(i-1))+j)=-1;
                    flag=1;
                    break;
                }
                else if(move==2)
                {
                    *(*(temp+i)+j)=*(*(temp+(i+1))+j);
                    *(*(temp+(i+1))+j)=-1;
                    flag=1;
                    break;
                }
                else if(move==3)

                {
                    *(*(temp+i)+j)=*(*(temp+i)+(j-1));
                    *(*(temp+i)+(j-1))=-1;
                    flag=1;
                    break;
                }
                else
                {
                    *(*(temp+i)+j)=*(*(temp+i)+(j+1));
                    *(*(temp+i)+(j+1))=-1;
                    flag=1;
                    break;
                }
            }
        }
        if(flag==1){break;}
    }
}

int childTraverse(int** curr,int** fin,int move)
{
    int** temp = new int*[3];
    for(int i=0;i<3;i++)
    {
        temp[i]=new int[3];
        for(int j=0;j<3;j++)
        {
            *(*(temp+i)+j)=*(*(curr+i)+j);
        }
    }
    makeMove(temp,move);
    printArray(temp);
    int man=manhattan(temp,fin);
    cout<<"The Manhattan number for this child is :"<<man<<endl<<endl<<endl;
    for(int i=0;i<3;i++)
    {
        delete temp[i];
    }
    delete temp;
    return man;
}
void steepestHillClimb( int** ini, int** fin,int previous)
{
    int arr[4]={99,99,99,99};
    cout<<"********************************************************************"<<endl;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(*(*(ini+i)+j)==-1)
            {
                if(i>0 && previous!=2)
                {
                    cout<<"Checking child (moving -1 up) "<<endl;
                    arr[0]=childTraverse(ini,fin,1);
                }
                if(i<2 && previous!=1)
                {
                    cout<<"Checking child (moving -1 down) "<<endl;
                    arr[1]=childTraverse(ini,fin,2);
                }
                if(j>0 && previous!=4)
                {
                    cout<<"Checking child (moving -1 left) "<<endl;
                    arr[2]=childTraverse(ini,fin,3);
                }
                if(j<2 && previous!=3)
                {
                    cout<<"Checking child (moving -1 right) "<<endl;
                    arr[3]=childTraverse(ini,fin,4);
                }
            }
        }
        cout<<endl;
    }
    int locOpt=99;
    int index=0;
    for(int i=0;i<4;i++)
    {
        if(arr[i]<locOpt)
        {
            locOpt=arr[i];
            index=i+1;
        }
    }
    makeMove(ini,index);
    cout<<"Next state (the one with minimum Manhattan number) :"<<endl;
    printArray(ini);
    if(locOpt==0)
    {
        cout<<"Solved! :)"<<endl;

        return;
    }
    else
    steepestHillClimb(ini,fin,index);
}

int main()
{
    int** initial = new int*[3];
    for(int i=0;i<3;i++)
    {
        initial[i]=new int[3];
    }

    int** final = new int*[3];
    for(int i=0;i<3;i++)
    {
        final[i]=new int[3];
    }

    int userEntry;
    cout<<"Enter initial 3x3 matrix (-1 as empty position) "<<endl;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<"Enter element A["<<i<<"]["<<j<<"]"<<endl;
            cin>>userEntry;
            initial[i][j]=userEntry;
        }
    }
    cout<<"Enter final 3x3 matrix (-1 as empty position) "<<endl;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
        {
            cout<<"Enter element A["<<i<<"]["<<j<<"]"<<endl;
            cin>>userEntry;
            final[i][j]=userEntry;
        }

    cout<<"Your initial matrix is :"<<endl;

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<*(*(initial+i)+j)<<"\t";
        }
        cout<<endl;
    }
    cout<<"\nYour final matrix is :"<<endl;

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<*(*(final+i)+j)<<"\t";
        }
        cout<<endl;
    }

    cout<<"Calling Stepest Hill Climbing function"<<endl;
    steepestHillClimb(initial,final,0);
    for(int i=0;i<3;i++)
    {
        delete initial[i];
        delete final[i];
    }
    delete initial;
    delete final;
  return 0;
}