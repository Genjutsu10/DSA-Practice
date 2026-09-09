


//! =========================================== Better Force.... ===========================================  



#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int n = nums.size();

        unordered_map<int,int> mp;
        vector<int> res;


        for( int i = 0; i < n ; i++ ){
            mp[nums[i]]++;
        }

        for( auto it : mp){
            if(it.second > n/3){
                res.push_back( it.first );
            }
        }

        return res;


    }
};





//! =========================================== Optimal condition .... =========================================== 




class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int n = nums.size();
        int cnt1 = 0, cnt2 = 0;
        int candidate_1 = INT_MIN;
        int candidate_2 = INT_MIN;

        for( int i = 0; i < n ; i++ ){

            if( cnt1 == 0 && nums[i] != candidate_2 ){
                cnt1++;
                candidate_1 = nums[i];
            }
            else if( cnt2 == 0 && nums[i] != candidate_1 ){
                cnt2++;
                candidate_2 = nums[i];
            }
            else if( candidate_1 == nums[i]){
                cnt1 ++;
            }
            else if( candidate_2 == nums[i] ){
                cnt2++;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }

        cnt1 = 0;
        cnt2 = 0;
        vector<int> res;

        for ( int i = 0 ; i < n ; i++ ){
            if( candidate_1 == nums[i] ) cnt1++;
            if( candidate_2 == nums[i] ) cnt2++;
        }
        if( cnt1 > n/3 ){
            res.push_back(candidate_1);
        }
        if( cnt2 > n/3 ){
            res.push_back(candidate_2);
        }

        return res; 

    }
};

