#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> findSubarray(vector<int>& arr) {
        
        int n = arr.size();
        
        int sum = 0;
        int maxima = arr[0];
        
        int end = 0 ;
        int start = 0 ;
        int ans_start = 0 ;
        
        for(int i = 0; i < n; i ++){
            
            if( sum == 0){
                start = i;
            }
            
            sum = sum + arr[i];
            
            if( sum > maxima){
                maxima = sum;
                ans_start = start;
                end = i;
                
            }
            
            if( sum < 0){
                sum = 0;
            }
            
        }
        return vector<int>(arr.begin() + ans_start , arr.begin() + end + 1); ;
    }
}; 