#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    void help( vector<vector<int>>& ans , vector<int>& res , int arrele , int k , int n , int sum , int i ){

        if( i == 9 ){
            if( res.size() == k  &&  sum == n ){
                   ans.push_back( res );
            }
            return ;
        }

        res.push_back( arrele );
        sum = sum + arrele;

        help( ans ,res , arrele+1 , k ,  n , sum , i+1 );

        sum = sum - arrele;
        res.pop_back();

        help( ans ,res , arrele+1 , k ,  n , sum , i+1 );

    }

    vector<vector<int>> combinationSum3(int k, int n) {

        int i = 0 ;
        int sum = 0;
        int arrele = 1;
        vector<int> res;
        vector<vector<int>> ans;

        help( ans ,res , arrele , k ,  n , sum , i );

        return ans;
        
    }
};

