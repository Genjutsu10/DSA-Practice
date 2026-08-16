

//! =========================================== Brute Force.... ===========================================



#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int x;
        int count;

        unordered_map<int,int>res;

        for(int i=0; i<n ;i++){
            res[nums[i]]++;
        }

        for(auto it : res){
            if( it.second==1){
                return it.first;
            }
        }
        return 0;
    }
};


//! =========================================== OPTIMAL CODE... ===========================================   XOR == love verity.....


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int max_count = INT_MIN;
        int result = 0;

        for(int i=0; i<nums.size(); i++){
            result = result^nums[i];
        }
        return result;
    }
};

