

//! ========================================  Striver Question.... =========================================== 

//? =========================================== Brute Force.... ===========================================  


#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> nextLargerElement(vector<int> arr) {

        int n = arr.size();

        for (int i = 0; i < n; i++) {

            for (int j = i+1; j < n; j++) {
                if (arr[i] < arr[j]) {
                    arr[i] = arr[j];
                    break;
                }
                if ( j == n-1 ) {
                    arr[i] = -1;
                }
            }
        }
        arr[n-1] = -1;
        return arr;
    }
};

//? =========================================== OPTIMAL CODE... ===========================================

/*

Start Iterating from the right cause u needed the right side greatest...



    1. Start traversing the array from right to left.

    2. The last element has no element on its right,
       so its Next Greater Element is -1.

    3. Push the current element of array into the stack.

    4. If the stack top is greater than the current element,
       then stack top is the Next Greater Element.
       Push the current element into the stack.

    5. If the stack top is smaller than the current element,
       keep popping the smaller elements from the stack.

    6. After popping:
       - If the stack becomes empty → NGE is -1.
       - Otherwise → stack top is the NGE.

    7. Finally, push the current element into the stack.

    8. Repeat this for all elements from right to left.


*/

class Solution {
public:
    vector<int> nextLargerElement(vector<int> arr) {

        int a;
        int n = arr.size();
        stack<int> st;

        for( int i = n-1; i >= 0; i-- ){

            if( i == n-1 ){
                a = arr[i];
                arr[i] = -1;
                st.push(a);
                continue;
            }
            if( arr[i] < st.top() ){
                a = arr[i];
                arr[i] = st.top();
                st.push(a);
            }else{
                a = arr[i];
                while( !st.empty() && arr[i] >= st.top() ){
                    st.pop();
                }

                if( st.empty() ){
                    arr[i] = -1;
                }else{
                    arr[i] = st.top();
                }
                st.push( a );
            }
        }
        return arr;
       
    }
};









//! ========================================  Leetcode Question.... =========================================== 

//? =========================================== Brute Force.... ===========================================  
// Using the TWO for loops...O(n^2) & O(1)...


class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        int n = nums1.size();
        int m = nums2.size();

        for( int i = 0 ; i < n ; i++ ){

            int max = INT_MAX;
            int sum = INT_MAX-1;

            for ( int j = 0; j < m ; j++ ){
                if( nums1[i] == nums2[j] ){
                    max = nums2[j];
                    sum = nums2[j];
                }
                if( max < nums2[j] ){
                    max = nums2[j];
                    break;
                }
                if( j == m-1 && max == sum ){
                    max = -1;
                }
            }
            nums1[i] = max;
        }
        return nums1;
    }
};

//? =========================================== OPTIMAL CODE... ===========================================


// same question like striver but here two vectore are given so se do the same right to left ans store them in map mp[arr[i]] = st.top();
// so that mean i stored the nge of each number of nums2..
// and if i want to get that element again for nums1 i can use the map where i stored that number and its nge


class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        int a;
        int n = nums2.size();
        int m = nums1.size();
        stack<int> st;
        unordered_map<int, int> mp;

        for (int i = n - 1; i >= 0; i--) {

            if (i == n - 1) {
                a = nums2[i];
                mp[nums2[i]] = -1;
                st.push(a);
                continue;
            }
            if (nums2[i] < st.top()) {
                a = nums2[i];
                mp[nums2[i]] = st.top();
                st.push(a);
            }else{
                a = nums2[i];
                while (!st.empty() && nums2[i] >= st.top()) {
                    st.pop();
                }

                if (st.empty()) {
                    mp[nums2[i]] = -1;
                }else{
                    mp[nums2[i]] = st.top();
                }

                st.push(a);
            }
        }

        for (int i = 0; i < m; i++) {
            nums1[i] = mp[nums1[i]];
        }
        return nums1;
    }
};


