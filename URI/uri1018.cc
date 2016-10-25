#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int day,mounth,year;

    cin>>day;

    year=day/365;
    cout << year <<endl;
    day=year%365;
    cout <<"day="<<day<<endl;
    mounth=day/30;
    cout << mounth <<endl ;
    day=day%30;

    cout << day<<endl;













}
