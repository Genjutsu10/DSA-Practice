


//! =========================================== Brute Force.... ===========================================


#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        int maxi = 0;
        int n = arr.size();
        
        for(int i=0; i<n; i++){
            int sum = 0;
            for(int j=i; j<n; j++){
                sum = sum + arr[j];
                
                if(sum == k){
                    maxi = max(maxi,j+1-i);
                }
            }
        }
        return maxi;
    }
};


//! =========================================== OPTIMAL CODE... ===========================================

class Solution {
public:
    int longestSubarray(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        int sum = 0;
        int maxlen = 0;

        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i];

            if (sum == k) {
                maxlen = i + 1;
            }

            if (mp.find(sum - k) != mp.end()) {      // agar tu map mai hoga to last eterater ko map nhi krega,
                maxlen = max(maxlen, i - mp[sum - k]); // means ki != means ki check is it in the map.. 
            }

            if (mp.find(sum) == mp.end()) {
                mp[sum] = i;
            }
        }

        return maxlen;
    }
};



