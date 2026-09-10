


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





//! =========================================== Optimal Code..... ===========================================  




class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        
        int n = arr.size();
        
        int count = 0;
        int XOR = 0;
        
        unordered_map<int,int>mp;
    
        for( int i = 0; i < n; i ++ ){
            
            XOR = XOR ^ arr[i];
            
            if( XOR == k){
                count ++;
            }
            
            int number = XOR ^ k; //a^b=c  then  c^a =b... ||  c^b = a...
                
            if( mp.find(number) != mp.end() ){
                count = count+mp[number];
            }
            
            mp[XOR]++;
            
        }
        return count;
        
    }
};



#include <vector>
#include <unordered_map>
using namespace std;

int subarraysWithXorK(vector<int> &a, int k) {
    int xr = 0;
    unordered_map<int, int> mpp;
    
    // Base case: prefix XOR 0 has occurred 1 time (handles subarrays starting from index 0)
    mpp[xr] = 1; 
    
    int cnt = 0;
    for (int i = 0; i < a.size(); i++) {
        // Prefix XOR till index i
        xr = xr ^ a[i];
        
        // Target prefix XOR required from the front: x = xr ^ k
        int x = xr ^ k;
        
        // Add frequency of target XOR to count
        cnt += mpp[x];
        
        // Store current prefix XOR in map
        mpp[xr]++;
    }
    
    return cnt;
}