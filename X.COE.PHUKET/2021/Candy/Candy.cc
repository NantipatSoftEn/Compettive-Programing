#include <iostream>
#include <cstdlib>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
    string str;
    std::set<int> v;
    std::set<int>::iterator it;
    int n;
    while(1){
        cin >> str;
        if(str=="A"){
           cin >> n;    
           v.insert(n);
        }
        
        else if(str=="Q"){
           if(v.empty()){
               cout << "empty" << endl;
           }
           else {
                it=v.begin();
                cout << *it << endl;
                v.erase (v.begin());
           }
           
        }
        else if(str=="X") break;
    }
    exit(EXIT_SUCCESS);
}