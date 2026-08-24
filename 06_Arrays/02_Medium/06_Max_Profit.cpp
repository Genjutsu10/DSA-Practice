

//! =========================================== Brute Force.... ===========================================  



#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();
        int maxi = INT_MIN;
        int sum;

        for( int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                sum = prices[j]-prices[i];
                maxi = max( sum , maxi );
            }
        }
        if( maxi < 0){
            return 0;
        }
        return maxi;       
    }
};