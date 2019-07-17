#include <iostream>
#include<cstdio>
#include<cmath>
using namespace std;

// most_significant_digit
long   msd(int N){
    double  K =  log10(N);
    cout << "log10 = " <<  K << endl;
    K = K - floor(K);
    cout << "K-floor(K)=" << K << endl; 
    int  X = pow(10,K);
   // cout <<" X= "<< X << endl;
    return X;
}
//  number of digits directly
long long int ndd(int N){
    return floor(log10(N)) + 1;  
}

int main() {
        int N ;
        cin >> N;
        cout <<"nnd ="<< ndd(N) << endl;
        cout << "msd=" <<msd(N) << endl;
}
