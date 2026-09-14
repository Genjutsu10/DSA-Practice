

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:	


    void help( vector<int>& res , vector<vector<int>>&ans , vector<int>& nums , int i , int n ){

        if( i == n ){
            ans.push_back( res );
            return;
        }

        res.push_back( nums[i] );

        help( res , ans , nums , i+1 , n );
        res.pop_back();
        help( res , ans , nums , i+1 , n );     
    }

    
    vector<vector<int> > powerSet(vector<int>& nums) {
        

        vector<int> res;
        vector<vector<int>> ans;
        int i = 0;
        int n = nums.size();

        help( res , ans , nums , i , n );

        return ans;

    }
};