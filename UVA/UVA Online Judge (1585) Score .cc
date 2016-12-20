#include <iostream>
#include <cstdlib>
#include <iostream>
#include <cstdlib>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int N;
	cin >> N;
	for(int i=0;i<N;i++)
	{
		int  sum=0;
		int  point=1;
		string str;
		cin >> str;
		for(int j=0;j<str.length();j++)
		{
			string str2=str.substr(j,1);
			if(str2=="O")
			{
				sum=sum+point;

				point++;
			}
			else if(str2=="X")
				point=1;	
		}
		cout << sum << endl;	
	}
    exit(EXIT_SUCCESS);
}