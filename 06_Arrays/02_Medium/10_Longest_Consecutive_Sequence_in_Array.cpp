

//! =========================================== Brute Force.... ===========================================  


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        int n = nums.size();
        if( n == 0){
            return 0;
        }
        
        int count = 1;
        int maxi = 1;

        sort( nums.begin() , nums.end() );

        for( int i = 0 ; i  < n-1 ; i++ ){

            if( nums[i]+1 == nums[i+1] ){
                count ++;
                maxi = max ( maxi , count );

            }
            else if( nums[i] == nums[i+1] ){}
            
            else{
                count = 1;
            }
        } 
        return maxi; 
    }
};


