


//! =========================================== Brute Force.... ===========================================  


#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int maxi = INT_MIN;
        int n = nums.size();
        int sum;

        for( int i = 0; i < n ; i++ ){
            sum = 1;
            for( int j = i; j < n; j++ ){
                sum = sum*nums[j];

                maxi = max ( sum , maxi);
            }
        }
        return maxi;
    }
};



//! =========================================== Optimal Solution..... =========================================== 
/*
kya bolu is algo ke baare maii..
bs ek jo sum start se krta hai aur ek last se krta haii..aur har ek iteration ke baad dono apna max store krte haiii...
koi bhi ek example lelo samjhne ke liye koi bhi jisme -ve numbers ho...

EX.[1,2,3,-5,-9,-4,4,2,6,1]..
just dry run it u will understand...


aur agar 0 aaya to sum = 1 ho jayegi... SIMPLE



*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int n = nums.size();

        if( n == 1){
            return nums[0];
        }

        int maxi = INT_MIN;

        int presum = 1;
        int suffsum = 1;

        for( int i = 0 ; i < n ; i++ ){
            
            presum = presum * nums[i];
            suffsum = suffsum * nums[n-1-i]; 

            maxi = max( maxi , max( presum ,suffsum ));

            if( presum == 0) presum = 1;
            if( suffsum == 0) suffsum = 1;

            
        }
        return maxi;
    }
};




