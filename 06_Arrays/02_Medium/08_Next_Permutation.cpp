

//! =========================================== Brute / Exceptional Force.... ===========================================  
//! Wrong Method 1 case not works 


#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    void nextPermutation(vector<int>& nums) {
    
    int n = nums.size();
    int i = n-1; 
    int critical = 0 ;
    int count = 0;
    int critical_index;  
        while( i > 0){

            if( nums[i] > nums[i-1] ){
                critical = nums[i-1];
                critical_index = i-1;
                count ++;
                break;
            }
            else{
                i--;
            }
        }

        if( count == 0){
            sort(nums.begin() + critical_index  , nums.end() );
        }
        else{
        
            sort(nums.begin() + critical_index + 1 , nums.end() );
            swap( nums[critical_index] , nums[critical_index + 1] ); 
        }
    }
};

//? 2,1,5,4,3  ANS:2,3,1,4,5
// uper wale mai ky aklr rhe haii ki pehle pivot dhundenge hai 4,3 cmp krnge kyu nhi pivot kyuki pehle 3,4 aata hai phir 4,3 uske baad unko change nhi kr skte( All possible combinations )
// phir aayenge 5,4 pr same logic
// 1,5 pe aayenge ab bn skta hai pivot = 1 kyoki 5,1 bn skta hai 1,5 ke baad 
// to pehle 1 ko pivot banayenge uske piche wale sort krenge [2,1,3,4,5]
// [2,1,3,4,5] --> pivot index aur pivot-1 index ko swap mar denge aa gya ans...

//! ye sb valid hai lekin agar question is like ki...
//! [2,3,1] tb hogi gned masti bnega 1,2,3 not correct so uper wala code ye wale condition ko fail marta haii...




//! =========================================== OPTIMAL CODE... ===========================================



class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        int n = nums.size();

        // Find the critical/pivot element from right
        int i = n - 1;
        int critical = 0;
        int critical_index = -1;

        while(i > 0){

            // First increasing pair from the right
            if(nums[i] > nums[i - 1]){
                critical = nums[i - 1];
                critical_index = i - 1;
                break;
            }
            else{
                i--;
            }
        }

        // No critical element → array is in descending order
        // So reverse it to get the smallest permutation
        //? yaha pe jo pura array hai wo reversed haiiii..

        if(critical_index == -1){
            reverse(nums.begin(), nums.end());
            return;
        }


        // Find the smallest element greater than critical
        // pichle condition ka H case ( jaha pe wo fail ho rhi thiii )
        
        int j = critical_index + 1;

        for(int k = critical_index + 1; k < n; k++){

            if(nums[k] > nums[critical_index] &&
               nums[k] < nums[j]){
                j = k;
            }
        }


        // Swap critical with the next greater element
        swap(nums[critical_index], nums[j]);

        // Arrange the remaining elements in ascending order
        sort(nums.begin() + critical_index + 1, nums.end());
    }
};