

//! =========================================== Brute Force.... ===========================================  



#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int maxima = nums[0];
        for(int i = 0; i < n; i++){
            sum=0;

            for(int j = i; j < n; j++){
                sum = sum + nums[j];
                maxima = max( maxima,sum);
            }
        }

        return maxima;
    }
};



//! =========================================== OPTIMAL CODE... ===========================================

//! =========================================== KADANE's ALGORITHMS ===========================================

/*

? WHAT is Kadane's Algorithm. ?

so what happens in brute code sum is going on and on and checks all over the code and sometimes it is becoming -ve...
so at this time we shouldn't carry that sum true means reset the value of sum i.e sum = 0.
btw we have used the max to cal maximum so there is no afffect on the maxima of overwriting the sum...
ek aur baat it doesn't depend on the value of nums[] agar sum -ve aa rha hai to terminate kro naa ki arr[i] = -ve aane pe..


summary 
brute : mai loop mai loop lga ke check krte every condition..
optimal : ek loop lgate sum ko maxima se me cmp krte sum -ve hai kya check krte.. hui to sum ko overwrite krte 0 .

*/




class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();

        int sum = 0;

        int maxima = nums[0];

        for(int i = 0; i < n; i++){
            
            sum = sum + nums[i];

            if( sum > maxima ){
                maxima = sum;
            }

            if( sum < 0){
                sum = 0;
            }
        }
        return maxima;
    }
};
 