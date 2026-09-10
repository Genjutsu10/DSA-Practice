


//! =========================================== Brute Force.... ===========================================  



#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        
        int n = arr.size();
        
        int count = 0;
        
        for( int i = 0; i < n; i ++ ){
            
            int sum = 0;
            
            for( int j = i; j < n; j++){
                
                sum = sum ^ arr[j];
                
                if( sum == k){
                    count ++;
                }
            }
        }
        return count;
        
    }
};