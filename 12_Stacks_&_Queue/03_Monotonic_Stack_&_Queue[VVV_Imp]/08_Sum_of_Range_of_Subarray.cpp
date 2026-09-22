
//! ========================================  Brute Force.... =========================================== 

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        
        int n = nums.size();
        int mini,maxi;
        long long sum = 0;

        for( int i = 0; i < n ; i++ ){

            mini = nums[i];
            maxi = nums[i];
            
            for( int j = i; j < n; j++ ){
                maxi = max( nums[j] , maxi );
                mini = min( nums[j] , mini );

                sum = sum + ( maxi - mini );
            }
        }
        return sum;
    }
};


