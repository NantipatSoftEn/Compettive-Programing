#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
float CalcMHWScore(vector<int> scores)
{
    double median;
    size_t size = scores.size();

    sort(scores.begin(), scores.end());

    if (size  % 2 == 0)
    {
        median = (double)(scores[size / 2 - 1] + scores[size / 2]) / 2;

    }
    else
    {
        median = scores[size / 2];
    }

    return median;
}
long   Mode(vector<int> s)
{
    long long modeS=s[0];
    int maxcount=0;
    for(int i=0; i<s.size(); i++)
    {
        int count =0;
        for(int k =0; k<s.size(); k++)
        {
            if(s[i]==s[k])
                count++;
        }
        if(maxcount < count )
        {
            maxcount=count;
            modeS=s[i];
        }
    }
    return modeS;

}
int main()
{

    int N,num,sum=0;
    cin>>N;
    vector<int> ar;
    for(int i=0; i<N; i++)
    {
        cin>>num;
        ar.push_back(num);
        sum+=ar[i];
    }

    printf("%.1f\n",(float)sum/N);
    printf("%.1f\n",CalcMHWScore(ar));
    sort(ar.begin(), ar.end());
    printf("%lld\n",Mode(ar));
    return 0;
}
