

//! =========================================== Brute Force.... ===========================================

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> rotate(vector<int> &arr) {
        
        int n = arr.size();
        
        vector <int> res;
        
        int i =0;
        int j;
        
        j = arr[n-1];
        for ( int i=n-1; i>0; i-- ){
            arr[i] = arr[i-1];
        }
        
        arr[0]=j;

        return arr;
    }
};

int main() {
    vector<int> arr = {3, 5, 1, 8, 2};

    Solution obj;

    obj.rotate(arr);

    for(int x : arr) {
        cout << x << " ";
    }

    return 0;
}









