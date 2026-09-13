

//! =========================================== NO RECURSIVE FUNCTION.... ===========================================  
// NO RECURSION FUNCTION....



#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        
        int i = 0;
        int n = s.size();


        // 1. Skip starting spaces
        while ( i<n && s[i] == ' ' ){
            i++;
        }


        // 2. decides the sign of the answer..
        int sign = 1;
        if( i<n && s[i] == '-' ){
            sign = -1;
            i++;
        }
        else if ( i<n && s[i] == '+' ){
            sign = +1;
            i++;
        }


        // 3. remaining string ke upar operations..
        long long result = 0;
        while( i < n && s[i] >= '0' && s[i] <= '9' ){   // ye he sambhal lega zeros ko bhii

            result = result *10 + ( s[i] - '0');  // s[i] + -'0' ascii value of s[i] - '0' gives the s[i] as number...

            if( sign * result > INT_MAX ) return INT_MAX;
            if( sign * result < INT_MIN ) return INT_MIN;

            i++;

        }

        return sign * result ;
    }
};



//! =========================================== WITH RECURSIVE FUNCTION.... ===========================================  


class Solution {
public:

    int helper( string &s , long long result , int sign , int i ){

        if( i == s.size() || s[i] < '0' || s[i] > '9' ){
            return sign * result;
        }

        result = result * 10 + ( s[i] - '0' );

        if (sign * result >= INT_MAX) return INT_MAX;
        if (sign * result <= INT_MIN) return INT_MIN;

        return helper ( s , result , sign , i+1 );
    }


    int myAtoi(string s) {
        
        int i = 0;
        int n = s.size();

        while( i < n && s[i] == ' ' ){
            i++;
        }

        int sign = 1;
        if ( i < n && s[i] == '-' ){
            sign = -1;
            i++;
        }
        else if ( i < n && s[i] == '+' ){
            i++;
        }
        int result = 0;

        return helper( s , 0 , sign , i );
    }
};



