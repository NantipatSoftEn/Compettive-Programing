#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    	int N;
	cin >> N;
	for(int i=1;i<N+1;i++)
	{
		int num1,num2;
		int sum=0;
		cin >> num1 >> num2;
		for(;num1<=num2;num1++)
		{
			if(num1%2==1)
				sum=sum+num1;
		}
		cout <<"Case "<< i<<": "<<sum <<endl;
	}
    exit(EXIT_SUCCESS);
}