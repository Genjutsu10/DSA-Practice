//! =========================================== Brute CODE.... ===========================================  


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    void count ( set<vector<int>>& result , vector<int>& candidates , int target , int sum , vector<int>& news , int i , int n){

        if( i == n ){
            if( sum == target ){
                result.insert( news );
            }
            return ;
        }

        if( sum > target ){
            return;
        }


        news.push_back( candidates[i] );
        sum = sum + candidates[i];

        count( result , candidates , target , sum , news , i+1 , n);

        sum = sum - candidates[i];
        news.pop_back();

        count( result , candidates , target , sum , news , i+1 , n );

        
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        int i = 0;
        int sum = 0;
        int n = candidates.size();

        vector<int>news;

        set<vector<int>> result;

        sort(candidates.begin(), candidates.end());

        count( result , candidates , target , sum , news , i , n );

        return vector<vector<int>> (result.begin() , result.end() );
        
    }
};


//! =========================================== Optimal CODE.... ===========================================  

class Solution {
public:

    void count ( vector<vector<int>>& result , vector<int>& candidates , int target , int sum , vector<int>& news , int i , int n){

        if( i == n ){
            if( sum == target ){
                result.push_back( news );
            }
            return ;
        }

        if( sum > target ){
            return;
        }


        news.push_back( candidates[i] );
        sum = sum + candidates[i];

        count( result , candidates , target , sum , news , i+1 , n);

        sum = sum - candidates[i];
        news.pop_back();

        while (i + 1 < n && candidates[i + 1] == candidates[i]) {
            i++;
        }

        count( result , candidates , target , sum , news , i+1 , n );

        
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        int i = 0;
        int sum = 0;
        int n = candidates.size();

        vector<int>news;

        vector<vector<int>> result;

        sort(candidates.begin(), candidates.end());

        count( result , candidates , target , sum , news , i , n );

        return result;
        
    }
};

