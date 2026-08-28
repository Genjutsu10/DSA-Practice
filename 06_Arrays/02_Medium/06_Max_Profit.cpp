

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


//! =========================================== OPTIMAL CODE... ===========================================



class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int min = prices[0];
        int max = 0;

        for( int i = 0; i < n; i++ ){

            if( prices[i] < min ){
                min = prices[i];
            }

            int diff = prices[i] - min;

            if( diff > max ){
                max = diff;
            }

        }
        return max;
               
    }
};



//! =========================================== CRAZZY OPTIMAL CODE... ===========================================


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int mini = prices[0];
        int maxi = 0;

        for( int i = 0; i < n; i++ ){

            mini = min( mini , prices[i] );

            int diff = prices[i] - mini;

            maxi = max( maxi , diff );

        }
        return maxi;
               
    }
};