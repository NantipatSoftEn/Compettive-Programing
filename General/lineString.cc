#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
void testA()
{
	char c;
	c=getchar();
	putchar(c);
	if(c=='?')
		cout <<"fucking";
		
}
void testB()
{
	char c;
	while((c=getchar())!='\n')
	{
		putchar(c);
	}
}
void testC()
{
	while(putchar(getchar())!='\n')
	{
		cout <<"FUCK\n";
	}
}
void testD()
{
	int n;
	char line[100];
	n=0;
	while(line[n++]=getchar()!='\n');
	line[n]='\0';
	printf("%d:\t%s",n,line );
}
void testE()
{
	string name;
 	cout << "Please, enter your full name: ";
  	getline (cin,name);
  	cout << "Hello, " << name << "!\n";
}
int main()
{
	testE();
}
