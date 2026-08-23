

//! =========================================== Brute Force.... ===========================================  
                    // O(n)    O(1)

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> res;

        unordered_map<int,int> mp;

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


                    // O(n)   O(1)


class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int n = nums.size();
        int count0 = 0;
        int count1 = 0;
        int count2 = 0;

        for(int i = 0; i < n; i++){
            if(nums[i] == 0){ count0++ ; }
            else if(nums[i] == 1){ count1++ ; }
            else if(nums[i] == 2){ count2++ ; }
        }

        for(int i = 0; i < count0; i++){
            nums[i] = 0;
        }
        for(int i = count0; i < count0+count1; i++){
            nums[i] = 1;
        }
        for(int i = count0+count1; i < count2+count0+count1; i++){
            nums[i] = 2;
        }


    }
};

  
                    // O(n^2)  O(1)

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


//! =========================================== OPTIMAL CODE... ===========================================


//! ===================================== DUTCH NATIONAL FLAG METHOD =====================================


class Solution {
public:
    void sortColors(vector<int>& arr) {
        
        int n = arr.size();
        int high = n-1;
        int low, mid = 0;

        while( mid <= high ){
            if( arr[mid] == 0){
                swap( arr[mid] ,arr[low] );
                mid ++;
                low ++;
            }else if ( arr[mid] == 1 ){
                mid ++;
            }else if ( arr[mid] == 2){
                swap( arr[mid] , arr[high] );
                high --;
            }
        }
    }
};

//?  23-08-2026








