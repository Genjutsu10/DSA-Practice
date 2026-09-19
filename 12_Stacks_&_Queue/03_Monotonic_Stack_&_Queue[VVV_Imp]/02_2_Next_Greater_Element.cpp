//! ========================================  Brute Force.... =========================================== 
 

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int> arr) {

        int n = arr.size();

        vector<int> original = arr;

        if( n == 1){
            arr[0] = -1;
            return arr;
        }

        for (int i = 0; i < n; i++) {

            for (int j = i + 1; j < i + n; j++) {

                int index = j % n;

                if (arr[i] < original[index]) {
                    arr[i] = original[index];
                    break;
                }

                if (j == i + n - 1) {
                    arr[i] = -1;
                }
            }
        }

        return arr;
    }
};        



//! =========================================== OPTIMAL CODE... ===========================================


/*

    We use ans because we are storing the answers
    separately without changing the original nums.

    We traverse 2*n elements because the array is circular.

    5 → 7 → 1 → 2 → 5 → 7 → 1 → 2

    nums → original elements
    ans  → stores the answers
    
*/


class Solution { 
public: 
    vector<int> nextGreaterElements(vector<int>& nums) { 
        
        int n = nums.size(); 
        vector<int> ans = nums; 
        int a; 
 
        stack<int> st; 
 
        for (int i = 2 * n - 1; i >= 0; i--) { 
 
            int index = i % n; 
            a = nums[index];

            while (!st.empty() && nums[index] >= st.top()) { 
                st.pop(); 
            } 
 
            if (st.empty()) { 
                ans[index] = -1; 
            } 
            else { 
                ans[index] = st.top(); 
            } 

            st.push(a); 
        } 
        
        return ans; 
    } 
};


