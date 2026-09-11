
// 11/09/2026

//! =========================================== Brute Force.... ===========================================  


#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int reversePairs(vector<int>& nums) {
        
        long long n = nums.size();

        long long count = 0 ;

        for( int i = 0; i < n; i++ ){

            for( int j = i+1 ; j < n ; j++ ){

                if( (long long)nums[i] > 2 * (long long)nums[j] ){
                    count ++;
                }
            }
        }
        return count;
    }
};





//! =========================================== Optimal Solution..... =========================================== 


/*
!Doubt 1 : arr[i] > arr[j] does not guarantee arr[i] > 2 * arr[j]...?? 

Inversion count: the array does not necessarily have to contain only positive numbers. The condition is simply arr[i] > arr[j], so negatives are fine too.
Reverse Pairs: the condition is arr[i] > 2 * arr[j], and because arr[j] can be negative, arr[i] > arr[j] does not guarantee arr[i] > 2 * arr[j].

? Example: negative numbers affect the overall

left = -5
right = -3

left > right?
-5 > -3  ❌


!Doubt 2 : arr[i] > arr[j] does not guarantee arr[i] > 2 * arr[j]. but can't we use the if ( arr[left] > 2*arr[right] )...??
arr[left] <= arr[right]

you could still have:

arr[left] > 2 * arr[right]

when values are negative.

? Example: some numbers which are    arr[left] <= arr[right]   can be    arr[left] > 2 * arr[right]...

left  = -5
right = -3



therefore... WE CAN'T ABLE TO TAKE THAT IN ELSE CONDITION...
*/


class Solution {
public:

    long long countt = 0;

    void merge(vector<int>& arr, int low, int mid, int high) {

        // Count Reverse Pairs
        int j = mid + 1;

        for(int i = low; i <= mid; i++) {

            while(j <= high && arr[i] > 2 * arr[j]) {
                j++;
            }

            countt += j - (mid + 1);
        }

        // Normal Merge
        vector<int> temp;

        int left = low;
        int right = mid + 1;

        while(left <= mid && right <= high) {

            if(arr[left] <= arr[right]) {
                temp.push_back(arr[left]);
                left++;
            }
            else {
                temp.push_back(arr[right]);
                right++;
            }
        }

        while(left <= mid) {
            temp.push_back(arr[left]);
            left++;
        }

        while(right <= high) {
            temp.push_back(arr[right]);
            right++;
        }

        for(int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }
    }

    void ms(vector<int>& arr, int low, int high) {

        if(low >= high)
            return;

        int mid = (low + high) / 2;

        ms(arr, low, mid);
        ms(arr, mid + 1, high);

        merge(arr, low, mid, high);
    }

    int reversePairs(vector<int>& nums) {

        countt = 0;

        ms(nums, 0, nums.size() - 1);

        return countt;
    }
};




