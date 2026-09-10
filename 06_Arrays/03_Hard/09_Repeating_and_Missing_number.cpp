


//! =========================================== Brute Force.... ===========================================  



#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> findTwoElement(vector<int>& arr) {

        sort(arr.begin(), arr.end());

        int n = arr.size();

        long long ogsum = 1LL * n * (n + 1) / 2;

        int rep;
        int miss;

        int sum = 0;

        for(int i = 0; i < n - 1; i++) {

            sum = sum + arr[i];

            if(arr[i] == arr[i+1]) {
                rep = arr[i];
            }
        }

        sum += arr[n-1];

        miss = ogsum - sum + rep ;

        return {rep, miss};
    }
};



