//! =========================================== Brute CODE.... ===========================================  



#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    void help( vector<int>& res , set<vector<int>>&ans , vector<int>& nums , int i , int n ){

        if( i == n ){
            ans.insert( res );
            return;
        }

        res.push_back( nums[i] );

        help( res , ans , nums , i+1 , n );
        res.pop_back();
        help( res , ans , nums , i+1 , n );

        
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {


        vector<int> res;
        set<vector<int>> ans;
        int i = 0;
        int n = nums.size();

        sort( nums.begin() , nums.end() );

        help( res , ans , nums , i , n );

        return vector<vector<int>> ( ans.begin() , ans.end() );
        
    }
};




//! =========================================== Optimal CODE.... ===========================================  


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
        while( i+1 < n && nums[i] == nums[i+1] ){
            i++;
        }
        
        help( res , ans , nums , i+1 , n );
      
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        vector<int> res;
        vector<vector<int>> ans;

        int i = 0;
        int sum = 0; 
        int n = nums.size();

        sort( nums.begin() , nums.end() );

        help( res , ans , nums , i , n );

        return ans;
        
    }
};
