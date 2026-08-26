

//! =========================================== Brute Force.... ===========================================  


#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {

        int n = nums.size();

        vector<int> res1;
        vector<int> res2;
        vector<int> res3;

        for( int i = 0; i < n; i++ ){
            if( nums[i] >= 0){
                res1.push_back(nums[i]);
            }else{
                res2.push_back(nums[i]);
            }
        }

        int x = res1.size();

        for( int i = 0 ; i < x ; i++ ){
            res3.push_back(res1[i]);
            res3.push_back(res2[i]);
        }
        return res3;

    }
};


//! =========================================== OPTIMAL CODE... ===========================================


