
//! ========================================  Brute Force.... =========================================== 

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        
        int n = nums.size();
        int mini,maxi;
        long long sum = 0;

        for( int i = 0; i < n ; i++ ){

            mini = nums[i];
            maxi = nums[i];
            
            for( int j = i; j < n; j++ ){
                maxi = max( nums[j] , maxi );
                mini = min( nums[j] , mini );

                sum = sum + ( maxi - mini );
            }
        }
        return sum;
    }
};


//! =========================================== OPTIMAL CODE... ===========================================


class Solution {
public:

    vector<int> findPSE(vector<int>& nums) {

        int n = nums.size();
        vector<int> pse(n);
        stack<int> st;

        for(int i = 0; i < n; i++) {

            while(!st.empty() && nums[st.top()] > nums[i]) {
                st.pop();
            }

            if(st.empty())
                pse[i] = -1;
            else
                pse[i] = st.top();

            st.push(i);
        }

        return pse;
    }


    vector<int> findNSE(vector<int>& nums) {

        int n = nums.size();
        vector<int> nse(n);
        stack<int> st;

        for(int i = n - 1; i >= 0; i--) {

            while(!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }

            if(st.empty())
                nse[i] = n;
            else
                nse[i] = st.top();

            st.push(i);
        }

        return nse;
    }


    vector<int> findPGE(vector<int>& nums) {

        int n = nums.size();
        vector<int> pge(n);
        stack<int> st;

        for(int i = 0; i < n; i++) {

            while(!st.empty() && nums[st.top()] < nums[i]) {
                st.pop();
            }

            if(st.empty())
                pge[i] = -1;
            else
                pge[i] = st.top();

            st.push(i);
        }

        return pge;
    }


    vector<int> findNGE(vector<int>& nums) {

        int n = nums.size();
        vector<int> nge(n);
        stack<int> st;

        for(int i = n - 1; i >= 0; i--) {

            while(!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }

            if(st.empty())
                nge[i] = n;
            else
                nge[i] = st.top();

            st.push(i);
        }

        return nge;
    }


    long long subArrayRanges(vector<int>& nums) {

        int n = nums.size();

        vector<int> pse = findPSE(nums);
        vector<int> nse = findNSE(nums);

        vector<int> pge = findPGE(nums);
        vector<int> nge = findNGE(nums);

        long long sumMin = 0;
        long long sumMax = 0;

        for(int i = 0; i < n; i++) {

            long long leftMin = i - pse[i];
            long long rightMin = nse[i] - i;

            long long leftMax = i - pge[i];
            long long rightMax = nge[i] - i;

            sumMin += 1LL * nums[i] * leftMin * rightMin;
            sumMax += 1LL * nums[i] * leftMax * rightMax;
        }

        return sumMax - sumMin;
    }
};


