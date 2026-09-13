


//! =========================================== Brute Force.... ===========================================  



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {

        if( n == 0 ){
            return 1;
        }
        if( n < 0 ){
            return 1/myPow(x,-n);
        }

        return x * myPow( x , n-1 );

    }
};




//! =========================================== Optimal Solution..... =========================================== 



class Solution {
public:
    double myPow(double x, int n) {
        
        long long N = n;

        if( N == 0 ){
            return 1;
        }

        if( N < 0 ){
            x = 1 / x ;
            N = -N;
        }

        double half = myPow(x*x,N/2);

        if( N % 2 == 0 ){
            return half;
        }else{
            return x*half;
        }
    }
};