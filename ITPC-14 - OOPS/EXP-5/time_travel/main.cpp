
#include <iostream>
using namespace std;

int main() {
    cout<<"Enter time in seconds:"<<endl;
    int t; cin >> t;
    string s;
    int  hrs_rem;
    if(t>86400)
        cout<<"invalid time"<<endl;
    else{
        int hrs;
        hrs=t/3600;
        hrs_rem=t%3600;
        s= s+ to_string(hrs)+" : ";
        
        int min;
        min=hrs_rem/60;
        int min_rem=hrs_rem%60;
        s=s+to_string(min)+" : " + to_string( min_rem);
        
        if(t>43200)
            s+="P.M";
        else
            s+="A.M";
    }
    
    cout<<s<<endl;;
    
    return 0;
}
