//! ========================================  Brute Force.... =========================================== 

// Time: O(n²) Space: O(n)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        
        int n = arr.size();

        vector<int>nums;
        
        for( int i = 0 ; i < n ; i++ ){

            int mini = arr[i];
            
            for( int j = i ; j < n; j++ ){
               mini = min( mini , arr[j] );
               nums.push_back( mini ) ; 
            }
        }

        int sum = 0;

        for( auto it : nums ){
            sum = (sum + it) % 1000000007;
        }
        return sum;
    }
};


//! =========================================== Better CODE... ===========================================


class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        
        int n = arr.size();
        long long sum = 0;
        
        for( int i = 0 ; i < n ; i++ ){

            int mini = arr[i];
            
            for( int j = i ; j < n; j++ ){
               mini = min( mini , arr[j] );
               sum = (sum + mini) % 1000000007;
            }
        }
        return sum;
    }
};



//! =========================================== OPTIMAL CODE... ===========================================


class Solution {
public:

    vector<int> find_nse(vector<int>& arr) {

        int n = arr.size();
        vector<int> nse(n);
        stack<int> st;

        for(int i = n - 1; i >= 0; i--) {

            while(!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            if(st.empty()) {
                nse[i] = n;
            }
            else {
                nse[i] = st.top();
            }

            st.push(i);
        }

        return nse;
    }


    vector<int> find_pse(vector<int>& arr) {

        int n = arr.size();
        vector<int> pse(n);
        stack<int> st;

        for(int i = 0; i < n; i++) {

            while(!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }

            if(st.empty()) {
                pse[i] = -1;
            }
            else {
                pse[i] = st.top();
            }

            st.push(i);
        }

        return pse;
    }


    int sumSubarrayMins(vector<int>& arr) {

        int n = arr.size();
        int MOD = 1000000007;

        vector<int> nse = find_nse(arr);
        vector<int> pse = find_pse(arr);

        long long sum = 0;

        for(int i = 0; i < n; i++) {

            long long left = i - pse[i];
            long long right = nse[i] - i;

            long long contri =
                (1LL * arr[i] * left * right) % MOD;

            sum = (sum + contri) % MOD;
        }

        return sum;
    }
};

