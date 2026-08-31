


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

/*

1. Har index pe sum me current element add karenge.
2. Agar sum == k , to 0 se i tak ki subarray ka sum k hai.
3. sum-k map me mila, to us index ke baad se i tak ka sum k hai.
4. Length = i - mp[sum-k] , aur maximum length store karenge.
5. Har sum ka sirf FIRST index store karenge, taaki maximum length mile. 

Example: [1,2,3], k=3
sum=6 → sum-k=3 → 3 pehle index 1 par mila
→ [3] ka sum = 3.

1) like pehle jayga 1 sum!=k rem not in the map 1 bhi map mai nhi haii map mai added 1.
2) phir gya 2 sum=3 == k so means ki lenght = 2;  rem=0 jo ki nhii haii to phir usko bhi dal diya aur apna "sum" ko map me dalenge
3) phir aa gya apna 3 sum=6 rem=3 jo ki hai lenght = 0; sum = 6 bhi map mai nhii hai usko bhi kr diya add..


*/



class Solution {
public:
    int longestSubarray(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        int sum = 0;
        int maxlen = 0;

        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i];                     // yaha pe kya kiya hai na ki chec kreneg ki sum = k hai ki nhii..

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



