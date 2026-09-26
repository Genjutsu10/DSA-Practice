//! ========================================  Brute Force.... =========================================== 


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        int n = nums.size();
        vector<int>res;

        if( n == 1){
            return nums;
        }

        for( int i = 0; i <= n-k; i++ ){

            int maxi = nums[i];

            for( int j = i; j < k+i; j++ ){
                if( nums[j] > maxi ){
                    maxi = nums[j];
                }
            }
            res.push_back(maxi);
        }
        return res;
        
    }
};

//! ========================================  Optimal Force.... =========================================== 


