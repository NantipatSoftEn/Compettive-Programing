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
}
bool compare_2(const pair<int, int>&i, const pair<int, int>&j)
{
        return i.second < j.second;
}
int main()
{
    int num1,num2;
    vector<pair<int,int > > v;
    v.push_back(make_pair(10,1));
    v.push_back(make_pair(20,3));
    v.push_back(make_pair(30,4));
    v.push_back(make_pair(40,40));
    v.push_back(make_pair(50,0));
    v.push_back(make_pair(60,0));
    std::sort(v.begin(),v.end(),compare);
    for(int i=0;i<6;i++)
    {
        cout << v[i].first <<" " << v[i].second <<endl;
    }
    v.erase(v.begin()+1);
    cout << "erase"<<endl;
    for(int i=0;i<6;i++)
    {
        cout << v[i].first <<" " << v[i].second <<endl;
    }
    return 0;
}



