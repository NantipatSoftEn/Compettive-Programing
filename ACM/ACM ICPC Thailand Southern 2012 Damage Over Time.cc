#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;
typedef struct{
    int D;
    int T;
}SKILL;

bool skilllnw(SKILL a,SKILL b){
    return a.D > b.D;
}

int main(){
    int n,m;
    cin >> n >> m;
    SKILL skill[n];
    for(int i=0;i<n;i++)
        cin >> skill[i].D >> skill[i].T;
    sort(skill,skill+n,skilllnw);
    int sum = 0;
    int mint = skill[0].T; 
    for(int i=0;i<m;i++){
        sum+= skill[i].D;
        if(skill[i].T < mint)
            mint = skill[i].T;
    }
    cout << sum << " " << mint; 
    
    exit(EXIT_SUCCESS);
}