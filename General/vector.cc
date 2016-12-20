#include<iostream>
#include<vector>
using namespace std;
void vectorrr()
{
	vector<vector<int> > vec;

    for(int i = 0; i < 5; i++)
    {
         vector<int> row;
         vec.push_back(row);
    }

    vec[0].push_back(5);
    vec[0].push_back(99);
    vec[0].push_back(88);
    vec[0].push_back(77);
    vec[0].push_back(66);
    vec[1].push_back(999);
    vec[1].push_back(991);
    vec[2].push_back(4);
    vec[3].push_back(555);
    for(int i = 0; i < 3; i++)
    	for(int j = 0; j < vec[i].size(); j++)
    		cout << vec[i][j] << endl;
}
void vectorrr2()
{
	vector<int> V[5];
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 2; j++)
			V[i].push_back(j);
	}
	for(int i = 0; i < 3; i++)
    	for(int j = 0; j < V[i].size(); j++)
    		cout << V[i][j] << endl;
	
}
void b()
{
	bool b=0;
	if(!b)
		cout <<"fuck";
	else cout <<"dont fuck";
}
int main()
{
	b();
}
