#include<iostream>
using namespace std;
int main()
{
    float  x,y;
    cin>>x>>y;
    if(x>0 && y>0)
        cout <<"Q1\n";
    else if(x<0 && y>0)
        cout <<"Q2\n";
    else if(x<0 && y<0)
        cout <<"Q3\n";
    else if(x>0 && y<0)
        cout <<"Q4\n";
    else if (x==0 && y!=0)
        cout << "Eixo Y" << endl;

    else if (x!=0 && y==0)
        cout << "Eixo X" << endl;

    else if (x==0 && y==0)
        cout << "Origem" << endl;


    return 0;
}
