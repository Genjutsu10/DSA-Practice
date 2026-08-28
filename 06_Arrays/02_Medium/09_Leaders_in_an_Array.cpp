

//! =========================================== Brute Force.... ===========================================  



#include<bits/stdc++.h>
using namespace std;


class Solution {
  public:
    vector<int> leaders(vector<int>& arr) {
        
        int n = arr.size();
        
        vector<int> res;
        
        for( int i = 0 ; i < n ; i++ ){
            
            int count = 0;
            
            for ( int j = i+1 ; j < n ; j++ ){
                
                if( arr[i] >= arr[j]){
                    count++;
                }
            }
            
            if( count == n-i-1){
                res.push_back(arr[i]);
            }
        }
        
        return res;
    }
};



//! =========================================== OPTIMAL CODE... ===========================================





class Solution {
  public:
    vector<int> leaders(vector<int>& arr) {
        
        int n = arr.size();
        
        vector<int> res;
        
        int maxnum = arr[n-1];
        
        for( int i = n-1 ; i >= 0 ; i-- ){
            
            if( arr[i] >= maxnum ){
                maxnum = arr[i];
                res.push_back(arr[i]);
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};