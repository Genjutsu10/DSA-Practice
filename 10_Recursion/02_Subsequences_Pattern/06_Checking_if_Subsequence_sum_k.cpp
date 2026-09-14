

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
  
  
    bool help( vector<int>& arr, int k, int i, int sum, int n ){
        
        if( i == n ){
            if( sum == k ){
                return true;
            }
            return false;
        }

        sum = sum + arr[i];
        
        if( help( arr , k , i+1 , sum , n) == true ){
            return true;
        }
        
        
        sum = sum - arr[i];
        
        if( help( arr , k , i+1 , sum , n) == true ){
            return true;
        }
        
    
    return false;       
        
    }
    
    
    
    bool checkSubsequenceSum( vector<int>& arr, int k ) {
        
        int n = arr.size();
        int i = 0;
        int sum = 0;
        
        return help( arr, k, i, sum, n );
        
    }
};