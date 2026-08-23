


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

        map<int,int>mp; 

        int n = nums.size();
        int number = 0;

        for(int i=0; i<n; i++){
            number = target - nums[i];
            if( mp.find(number) != mp.end() ){ 
                return {i,mp[number]};
            }
            mp[nums[i]]=i; // yaha pr humm logo ne mp[number] kyo nhi liya ??   
        return {};         // arr = {2,5} target=7 isme pehlr map mai 7-2 nhi tha (infact kuch bhi nhi tha..) fir map me jayega 5 (3 jana chahiye tha.. magar arr[number])         
        }                  // fir 5 ki bazri aayi 7-5 map main nhi haiii yahi problrm hai ki vo hona chahiy tha map maii kyoki arr galat ngi hai method galat hai is liye use kro mp[arr[i]]
    }                    // yaha pr hashing baad mai kyu ki start mai krke cmp bhi kr sakte the.. 
};                       // koyki agar arr={3}  hai 6=target aur usko kr diya map mai store.apna sum = 3, aur 3 is in the map that means ans is (1,1) nopeee..