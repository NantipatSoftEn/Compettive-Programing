#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        char c[101];
        int fuck=0;
        scanf("%s",c);
        for(int i=0; i<101; i++)
        {
            if(c[i]=='\0')
                break;
            else if(c[i]=='1')
                fuck+=2;
            else if(c[i]=='2')
                fuck+=5;
            else if(c[i]=='3')
                fuck+=5;
            else if(c[i]=='4')
                fuck+=4;
            else if(c[i]=='5')
                fuck+=5;
            else if(c[i]=='6')
                fuck+=6;
            else if(c[i]=='7')
                fuck+=3;
            else if(c[i]=='8')
                fuck+=7;
            else if(c[i]=='9')
                fuck+=6;
            else if(c[i]=='0')
                fuck+=6;
        }
        cout << fuck<<" leds"<<endl;
    }
    return 0;
}
