


//! =========================================== Brute Force.... ===========================================  



#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        set<vector<int>>res;

        int n = nums.size();

        for( int i = 0; i < n ; i++ ){
            for( int j = i+1; j < n; j++ ){
                for( int k = j+1 ; k < n ; k++ ){
                    for( int l = k+1 ; l < n ; l++ ){

                        int sum = target - (nums[i] + nums[j] + nums[k] + nums[l]);

                        if ( sum == 0 ){
                            vector<int>st = { nums[i] , nums[j] , nums[k] , nums[l] };
                            sort( st.begin() , st.end() );
                            res.insert(st);
                        }

                    }
                }
            }
        }
        return vector<vector<int>>(res.begin(),res.end());


    }
};




//! =========================================== Betterr Force.... ===========================================  





class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        set<vector<int>>res;

        int n = nums.size();

        for( int i = 0; i < n ; i++ ){
            for( int j = i+1; j < n; j++ ){
                unordered_set<int>st;
                for( int k = j+1 ; k < n ; k++ ){

                    int sum = target - (nums[i] + nums[j] + nums[k]);
                    if ( st.find( sum ) != st.end() ){
                        vector<int>v1 = { nums[i] , nums[j] , nums[k] , sum};
                        sort( v1.begin() , v1.end() );
                        res.insert(v1);
                    }else{
                        st.insert(nums[k]);
                    }
                }
            }
        }
        return vector<vector<int>>(res.begin(),res.end());


    }
};






//! =========================================== Optimal condition .... =========================================== 





class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        vector<vector<int>>res;

        sort(nums.begin(), nums.end());
        int n = nums.size();

        for( int i = 0; i < n ; i++ ){
            if( i>0 && nums[i] == nums[i-1] ) continue;
            int target1 = target - nums[i];
            for ( int j = i + 1 ; j < n ; j++ ){
                if( j>i+1 && nums[j] == nums[j-1] ) continue;

                int k = j+1;
                int l = n-1;

                while(k < l){
                    int sum = (nums[l]+nums[j]+nums[k]);
                    if( sum < target1 ){
                        k++;
                    }else if ( sum > target1 ){
                        l--;
                    }else{
                        vector<int>v1 = { nums[i],nums[j],nums[k],nums[l] };
                        res.push_back(v1);
                        l--;
                        k++;
                        while( k<l && nums[k]==nums[k-1]) k++;
                        while( k<l && nums[l]==nums[l+1]) l--;
                    }
                    
                }

            }
        }
        return res;
    }
};