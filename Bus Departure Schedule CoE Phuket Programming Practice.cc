#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int N;
    cin >> N ;
	
	int j=0;
	while(j<N)
	{
		int T;
		cin >> T;
		int m[3];
		float sum=0;
		for(int i=0;i<3;i++)
		{
			cin >>m[i];
			sum=sum+m[i];	
		}
	
		int count=0;
		do{
			sum=sum-60;
			count++;
		
	 }while(sum>=60);
	 	T=T+count;
	 	sum=sum/100;
	
		if(sum>0)
			T=T+1;
		if(T>=23)
			cout <<"NO" <<endl;
		else
		cout<< T << endl;
		j++;	
	}	
    exit(EXIT_SUCCESS);
}