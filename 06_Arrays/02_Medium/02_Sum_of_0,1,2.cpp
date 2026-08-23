

//! =========================================== Brute Force.... ===========================================  
                    // O(n)

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> res;

        map<int,int> mp;

        for(int i = 0 ; i < n; i++ ){
            mp[arr[i]]++;
        }

        arr = res;

        for(int i = 0; i < mp[0]; i++){
            arr.push_back(0);
        }
        for(int i = 0; i < mp[1]; i++){
            arr.push_back(1);
        }
        for(int i = 0; i < mp[2]; i++){
            arr.push_back(2);
        }
    }
};


//! =========================================== Brute Force.... ===========================================  
                    // O(n^2)

class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int n = nums.size();

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n-1-i; j++){
                if(nums[j]>=nums[j+1]){
                    swap(nums[j],nums[j+1]);
                }
            }
        }

    }
};







