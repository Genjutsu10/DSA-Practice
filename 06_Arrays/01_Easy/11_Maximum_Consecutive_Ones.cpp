

//! =========================================== Brute Force.... ===========================================



#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                count ++;    
            }else{
                res.push_back(count);
                count = 0;
            }
            
            
        }

        res.push_back(count);
        int m = res.size();
        int high = res[0];
        for (int i=0; i<m; i++){
            if( high<=res[i]){
                high = res[i];
            }
        }
        if( high == 0 ){
            return 0;
        }
        
        return high;
    }
};



//! =========================================== OPTIMAL CODE... ===========================================


class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();

        int maxcount = 0;
        int count = 0;

        for(int i = 0; i<n; i++){
            if( nums[i] == 1 ){
                count ++;
                maxcount = max( maxcount , count);
            }else{
                count = 0;
            }
        }
        return maxcount;
    }
};
