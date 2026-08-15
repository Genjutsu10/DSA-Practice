#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int n = nums.size();

        int i = 0;

        for(int j=1; j<n; j++){

            if( nums[i] == 0 && nums[j] != 0){
                swap(nums[i],nums[j]);
                i++;
                
            }else if( nums[i] != 0){
                i++;
            }
        }

        
    }
};