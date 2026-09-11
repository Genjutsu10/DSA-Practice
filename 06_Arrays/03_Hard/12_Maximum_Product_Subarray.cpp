


//! =========================================== Brute Force.... ===========================================  


#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int maxi = INT_MIN;
        int n = nums.size();
        int sum;

        for( int i = 0; i < n ; i++ ){
            sum = 1;
            for( int j = i; j < n; j++ ){
                sum = sum*nums[j];

                maxi = max ( sum , maxi);
            }
        }
        return maxi;
    }
};




//! =========================================== Optimal Solution..... =========================================== 






