#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int main()
{
    int n,pick[1000];
    int i;
    while(true)
    {
        cin>>n;
        if(n==0)
            break;
        while(true) 
        {
            cin>>pick[0];
            if(pick[0]==0)
            {
                cout<<endl;
                break;
            }
            
            for(i=1;i<n;i++)
            {
                cin>>pick[i];
               
            }
            int tran=1,target=0;
             stack<int> station;
            while(tran<=n)
            {
                station.push(tran);
                while(!station.empty()&& station.top()==pick[target])
                {
                    station.pop();
                    target++;
                    if(target>=n)
                        break;
                }
                tran++; 
            }
            if(station.empty())
                cout<<"Yes"<<endl;
            else 
                cout<<"No"<<endl;
        }
    }
        
    return 0;
}