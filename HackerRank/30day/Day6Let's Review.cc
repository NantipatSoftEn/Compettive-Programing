#include<iostream>
using namespace std;
int main()
{
    int rem=0,s=0,t=0,n=0;
    cin>> n;
    while(n>0)
    {
        cout <<"n="<<n<<endl;
        rem=n%2;  //   LSB
        cout <<"rem="<< rem<<endl;
        n/=2;
        cout <<"n="<<n<<endl;
        if(rem==1)
        {
            cout <<"cheak1"<<endl;
            s++;
            cout <<"s=" <<s<<" "<<"t="<<t<<endl;
            if(s>=t)
            {
                cout << "cheak2\n";
                t=s;
                cout <<"t="<<t<<endl;
            }

        }
        else
        {
            cout <<"cheak2"<<endl;
            s=0;
        }
    }
   cout << t <<endl;
    return 0;
}
