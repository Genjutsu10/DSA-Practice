#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:

    void count ( vector<int>& result , vector<int>& nums , int sum , vector<int>& news , int i , int n){

        if( i == n ){

            result.push_back( sum );
            return ;
        }


        news.push_back( nums[i] );
        sum = sum + nums[i];

        count( result , nums , sum , news , i+1 , n);

        sum = sum - nums[i];
        news.pop_back();

        count( result , nums , sum , news , i+1 , n );

        
    }


    vector<int> subsetSums(vector<int>& nums) {

        int i = 0;
        int sum = 0;
        int n = nums.size();

        vector<int>news;
        vector<int> result;

        count( result , nums , sum , news , i , n );
        return result;

    
    }
};