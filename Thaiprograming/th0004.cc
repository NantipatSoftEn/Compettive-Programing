#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    /*int i=0;
    char str[]="Test String.\n";
    char c;
    while (str[i])
    {
        c=str[i];
        if (isupper(c))
            c=tolower(c);
        putchar (c);
        i++;
    }
    retu*/
    char str[10000];
    bool cheak1=false,cheak2=false;
    scanf("%s",str);
    int i=0;
    while(str[i])
    {
        if(isupper(str[i]))
            cheak1=true;
        if(islower(str[i]))
            cheak2=true;
        i++;
    }
    if(cheak1==true && cheak2==false)
        cout <<"All Capital Letter"<<endl;
    else if(cheak1==false && cheak2==true)
        cout <<"All Small Letter"<<endl;
    else  cout <<"Mix"<<endl;

    return 0;
}
