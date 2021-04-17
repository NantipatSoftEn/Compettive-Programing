#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;


int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;
  
        // If the element is present at the middle
        // itself
        if (arr[mid] == x)
            return mid;
  
        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
  
        // Else the element can only be present
        // in right subarray
        return binarySearch(arr, mid + 1, r, x);
    }
  
    // We reach here when element is not
    // present in array
    return -1;
}

int main()
{
    int n,m,h;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    sort(arr,arr+n);
    cin >> m;
    int search[m];
    for(int i=0;i<m;i++){
        cin >> search[i];
    }
    
    for(int i=0;i<m;i++){
        int result = binarySearch(arr, 0, n - 1, search[i]); 
        if(result==-1)
        cout << search[i] <<" is not found." << endl;
        else cout << search[i] <<" is found." << endl;
    }
    exit(EXIT_SUCCESS);
}