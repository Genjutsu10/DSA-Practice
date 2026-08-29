

//! =========================================== Brute Force.... ===========================================  


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        int n = nums.size();
        if( n == 0){
            return 0;
        }
        
        int count = 1;
        int maxi = 1;

        sort( nums.begin() , nums.end() );

        for( int i = 0 ; i  < n-1 ; i++ ){

            if( nums[i]+1 == nums[i+1] ){
                count ++;
                maxi = max ( maxi , count );

            }
            else if( nums[i] == nums[i+1] ){}

            else{
                count = 1;
            }
        } 
        return maxi; 
    }
};



//! =========================================== BETTER CODE... ===========================================
//! ============================== NEARLY OPTIMAL JUST USE SET CODE... ===================================

/*

1) pehle sb elements of arr set mai daal denge...

2) phir check krnege every elemnt ko ki usse -1 koi number haii kya us set maii,
   like there is 2 in set then check is ther 1 in the set or not..
   agar hua to current++ kyoki wo element is not starting element [1,2,3] 2 se start to nhi kr skte na...count galat aayega...

3) abhi us loop mai while condition lagaya haii agar current ka -1 present nhi hoga to wo current is first number..
   agar wo current is first number then check the current +1 is there or not..and do count++ and abhi new current is that new number which is old+1
   ahgar nhi mila to count is reinitialized...







*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        int n = nums.size();

        if(n == 0){
            return 0;
        }

        // Store all numbers for O(1) average lookup
        unordered_map<int, int> mp;

        for(int i = 0; i < n; i++){
            mp[nums[i]]++;
        }

        int maxi = 1;

        // Check every number
        for(int i = 0; i < n; i++){

            // If previous number doesn't exist,
            // nums[i] is the START of a sequence
            if(mp.find(nums[i] - 1) == mp.end()){

                int current = nums[i];
                int count = 1;

                // Move forward: x -> x+1 -> x+2...
                while(mp.find(current + 1) != mp.end()){
                    current++;
                    count++;
                }

                maxi = max(maxi, count);
            }
        }

        return maxi;
    }
};



//! =========================================== OPTIMAL CODE... ===========================================



class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int> st;

        for(int num : nums){
            st.insert(num);
        }

        int maxi = 0;

        for(int num : st){

            // Start counting only if num is the
            // beginning of a sequence
            if(st.find(num - 1) == st.end()){

                int current = num;
                int count = 1;

                while(st.find(current + 1) != st.end()){
                    current++;
                    count++;
                }

                maxi = max(maxi, count);
            }
        }

        return maxi;
    }
};
