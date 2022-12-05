#include<bits/stdc++.h>
using namespace std;
//comparison b/w selection techniques:
/*
1.Rank Based selection
2.Tournament selection
3.Roulette-wheel selection
*/
void roulette_wheel_selection(int n,vector<pair<char,float>> v){
   //sum of fitness values
   float totalSum=0;
   for(auto it: v)
   {
    totalSum+=it.second;
   }
   // area of each individual will be fi/totalSum
   vector<pair<char,float>> selection;
   for(auto it: v)
   {
      char chromosome=it.first;
      float percentage=(float(it.second)/totalSum)*100;
      selection.push_back({chromosome,percentage});
   }
   cout<<"Roulette wheel distributsion of individuals is:"<<endl;
   for(auto it:selection)
   {
    cout<<it.first<<"------------->"<<it.second<<"%"<<endl;
   }
}
bool compare(pair<char,float> &a,pair<char,float> &b)
{
    return a.second<b.second;
}
void rank_based_selection(int n,vector<pair<char,float>> v)
{
   sort(v.begin(),v.end(),compare);
   //rank array
   vector<pair<char,int>> rankArr;
   int i=1;
   for(auto it: v)
   {
     rankArr.push_back({it.first,i});
     i++;
   }
   //sum of ranks
   int rankSum=0;
   for(auto it: rankArr){
    rankSum+=it.second;
   }
   //percentage on basis of rank r_i/rankSum
   vector<pair<char,float>> selection;
   for(auto it: rankArr)
   {
     float percentage=((float)it.second/rankSum)*100;
     selection.push_back({it.first,percentage});
   }
   cout<<"Rank based distributsion of individuals is:"<<endl;
   for(auto it:selection)
   {
    cout<<it.first<<"------------->"<<it.second<<"%"<<endl;
   }
}

void tournament_selection(int n,vector<pair<char,float>> v)
{
    int k;
    cout<<"Enter no. of k-individuals to be selected:";
    cin>>k;
    pair<char,float> random1,random2;
    int random;
    vector<pair<char,float>> selection;
    for(int i=0;i<k;i++)
    {
        //first random value
        random= rand()%v.size();
        random1.first=v[random].first;
        random1.second=v[random].second;
        //finding index of given random value in array v
        v.erase(v.begin()+random);
        //second random value
        random=rand()%v.size();
        random2.first=v[random].first;
        random2.second=v[random].second;
        v.erase(v.begin()+random);
        if(random1.second>random2.second) selection.push_back({random1.first,random1.second});
        else selection.push_back({random2.first,random2.second});
    }
   cout<<"Tournament based selection of "<<k<<" individuals is:"<<endl;
   for(auto it:selection)
   {
    cout<<it.first<<"------------->"<<it.second<<endl;
   }
}

int main()
{
  int n;
  cout<<"Enter no. of individuals in intial population:";
  cin>>n;
  vector<pair<char,float>> v;//array to store fitness of n individuals
  char ch;
  float value;
  cout<<"Enter name and fitness values of n individuals:"<<endl;
  for(int i=0;i<n;i++){
    cin>>ch;
    cin>>value;
    v.push_back({ch,value});
  }
  cout<<"Initial individuals and their fitness values:"<<endl;
  for(auto it: v)
  {
    cout<<it.first<<"------------->"<<it.second<<endl;
  }
  //rank_based_selection(n,fitness);
  roulette_wheel_selection(n,v);
  rank_based_selection(n,v);
  tournament_selection(n,v);
  return 0;
}