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



//! =========================================== COUNT of number of non consecutive 1's ....===========================================  


class Solution {
  public:
    
    int count(string &s , int n , int i ){
        

        if(i == n){
            return 1;
        }
        
        s.push_back('0');
        int a = count( s , n , i+1 );
        s.pop_back();
        
        int b;
        
        if(i == 0 || s.back() == '0') {
            s.push_back('1');
            b = count(s, n, i + 1);
            s.pop_back();
        }
        
        return a+b;
    }
  
    int countStrings(int n) {
        
        string s;
        int i = 0;
        return count( s , n , i );
        
    }
};



