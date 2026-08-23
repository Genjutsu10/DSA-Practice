


//! =========================================== Brute Force.... ===========================================  

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        vector<int> res;

        int n = nums.size();

        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                if(nums[i]+nums[j] == target){
                    return {i,j};
                }
            }
        }
        return {};
    }
};


//! =========================================== Optimal condition .... ===========================================  37


// todo mp[nums[i]]=i; btw this is index mapping...


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i = 0;

        map<int,int>mp; 

        int n = nums.size();
        int sum = 0;

        for(int i=0; i<n; i++){
            sum = target - nums[i];
            if( mp.find(sum) != mp.end() ){
                return {i,mp[sum]};
            }
            mp[nums[i]]=i;   // yaha pr hashing baad mai kyu ki start mai krke cmp bhi kr sakte the.. 
        return {};           // koyki agar arr={3}  hai 6=target aur usko kr diya map mai store.apna sum = 3, aur 3 is in the map that means ans is (1,1) nopeee..
        }
    }
};