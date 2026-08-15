#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int largest(vector<int> &arr) {
        
        int high = arr[0];
        int n = arr.size();
        
        for (int i=0; i<n; i++){
            if( high<=arr[i]){
                high = arr[i];
            }
        }
        return high;
        
    }
}; 

int main() {
    vector<int> arr = {3, 5, 1, 8, 2};

    Solution obj;

    cout << obj.largest(arr);

    return 0;
}
