#include<iostream>
#include<cstdio>
#include<utility>
#include<vector>
#include<algorithm>
using namespace std;
bool compare(const pair<int, int>&i, const pair<int, int>&j)
{
    if(i.first < j.first )
        return i.second < j.second;
    return  i.first > j.first;
}

int main()
{
    int num1,num2,N,L;
    vector<pair<int,int > > v;
    int  b[N];
    cin>>N>>L;
    for(int i=0;i<N;i++)
    {
        cin>>num1>>num2;
        v.push_back(make_pair(num1,num2));
        b[i]=0;
    }
    sort(v.begin(),v.end(),compare);
    int sum=0;
    for(int i=0;i<N;i++)
    {
            if(L<=0) break;
            L-=v[i].second;
            sum+=v[i].first;
            b[i]=1;
    }
    for(int i=0;i<N;i++)
    {
        if(b[i]==0)
            sum-=v[i].first;
    }
    cout << sum<<endl;
}



