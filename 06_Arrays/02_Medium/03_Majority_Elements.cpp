

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


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        unordered_map<int,int> mp;

        int n = nums.size();

        int count = 0;
        int candidate = 0;
        for( int i=0; i<n; i++){

            if( count == 0 ){
                candidate = nums[i];     
            }

            if( nums[i] == candidate){
                count++; 
            }
            else{
                count--;
            }

        }

        return candidate;
    }
};


/*
This idea of candidate - count is crazy...

pehle kya huua count 0 tha tb arr[i] ko candidate bna diya phir jb jb wo bnada repeat hoga,,
tb tb (count ++) hoga lekin jaise he wo nhi milega (count --) hoga lekin candidate change nhi hoga...
imagine koi candidate 5 baar mil gya to ab uska count = 5 hai, lekin ab es wali iteration mai nhi mila..
that doesnt mean ki wo max nhi ho skta jb tk count -- ho krke 0 nhi krta tb tk wahi hoga cnadidate..

aisa kyuuu ??
q. mai diyahai ki majority matlab half of the array se bhi jyada count...
? assume that the majority element always exists in the array. 
agar exterem case bhi aa gyi to bhi wahi candidate hoga uper ki condition..
means ki agar {1,1,1,2,2,2,1} aaya to bhi count 1 nhi ho payega...





*/
