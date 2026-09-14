

#include<bits/stdc++.h>
using namespace std;


class Solution{
    public:

    int count( vector<int>& nums, int k, int i, int sum ,int n){

        if( i == n ){
            if ( sum == k ){
                return 1;
            }
            return 0;
        }

        sum = sum + nums[i];

        int a = count( nums , k , i+1 , sum , n);

        sum = sum - nums[i];

        int b = count( nums , k , i+1 , sum , n);

        return a + b;
    }

    int countSubsequenceWithTargetSum(vector<int>& nums, int k){

        int n = nums.size();
        int i = 0;
        int sum = 0;

        return count( nums , k , i , sum , n );
    
    }
};