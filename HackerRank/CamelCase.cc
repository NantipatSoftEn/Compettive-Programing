#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>


using namespace std;
int main() {

 string str;
 int cnt = 1;
 cin >> str;
 int len = str.length();
 for(int i = 0; i < len; i++){
        if(str[i]>= 65 && str[i] <= 90)cnt++;
 }
 cout << cnt << endl;
 return 0;
}
