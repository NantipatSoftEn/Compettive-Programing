#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
int knapSack(int W, int wt[], int val[], int n)
{
    int i, w;
    int K[n + 1][W + 1];
    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w]
                    = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    return K[n][W];
}
int main()
{


    map<string,int > mp;
    mp["HANDGUN"]=2;
    mp["RED9"]=3.5;
    mp["BLAKTAIL"]=3.5;
    mp["MATILDA"]=2;
    mp["HANDCANNON"]=60;
    mp["STRIKER"]=12;
    mp["TMP"]=1.2;
    mp["RIFLE"]=1.2;
    map<string,int > mp_2;
    mp_2["GANADOS"]=50;
    mp_2["COBRAS"]=40;
    mp_2["ZEALOT"]=75;
    mp_2["COLMILLOS"]=60;
    mp_2["GARRADOR"]=125;
    mp_2["LASPLAGAS"]=100;
    mp_2["GATLINGMAN"]=150;
    mp_2["REGENERATOR"]=250;
    mp_2["ELGIGANTE"]=500;
    mp_2["DR.SALVADOR"]=350;
    int  N;
    while(cin>>N)
    {
        int val[500],wt[500],bullet,c=0;
        string gun;
        for(int i=0; i<N; i++)
        {
            cin>> gun>> bullet;
            while(bullet--)
            {
                val[c]=mp[gun];
                wt[c]=1;
                c++;
            }
        }
        int M;
        cin>>M;
        string moster;
        int val_monster,result_monster=0;
        for(int i=0; i<M; i++)
        {
            cin>> moster>> val_monster;
            result_monster+=mp_2[moster]*val_monster;
        }

        int W;
        cin>>W;

        if(knapSack(W,wt,val,c)> result_monster)
            cout <<"Missao completada com sucesso"<<endl <<endl ;
        else  cout <<"You Are Dead"<<endl<<endl<<endl;
    }
    return 0;
}
