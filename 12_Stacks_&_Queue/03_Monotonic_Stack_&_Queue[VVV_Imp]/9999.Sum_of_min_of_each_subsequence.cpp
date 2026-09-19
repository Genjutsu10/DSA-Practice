 

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    void help( vector<int>& arr , vector<int>& nums , int n , int& sum , int i ){

        if( i == n ){

            int mini = INT_MAX;

            for( auto it : nums ){
                mini = min( mini , it );
            }
            sum = sum + mini;
            return ;
        }

        nums.push_back( arr[i] );
        help( arr , nums , n , sum , i+1 );

        nums.pop_back();
        help( arr , nums , n , sum , i+1 );

    }

    int sumSubarrayMins(vector<int>& arr) {

        int i = 0;
        int n = arr.size();
        int sum = 0;

        vector<int> nums;

        help( arr , nums , n , sum , i );

        return sum;    
    }
};