

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:

    void count(string &s , int n , int i , vector<string>& q ){
        
        if(i == n){

            q.push_back(s);          
            return ;
        }
        
        s.push_back('0');
        count( s , n , i+1 ,q );
        s.pop_back();
               
        if(i == 0 || s.back() == '0') {
            s.push_back('1');
            count(s, n, i + 1 ,q );
            s.pop_back();
        }
        
    }


    vector<string> generateBinaryStrings(int n) {

        string s;
        vector<string> q;
        int i = 0;

        count( s , n , i , q );
        return q;

    }
};


