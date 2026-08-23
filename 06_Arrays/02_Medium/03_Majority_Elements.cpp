

//! =========================================== Brute Force.... ===========================================  
                    // O(n)    O(n)


#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        unordered_map<int,int> mp;

        int n = nums.size();

        for(int i = 0; i < n; i++){
            mp[nums[i]]++;
        }
        int appearance = 0;
        int number;
        for( auto it : mp){
            if( it.second > appearance ){
                appearance = it.second;
                number = it.first;
            }
        }
        return number;
    }
};



//! =========================================== OPTIMAL CODE... ===========================================


