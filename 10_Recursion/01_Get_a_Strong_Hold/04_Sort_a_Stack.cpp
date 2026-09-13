

//! =========================================== NO RECURSIVE FUNCTION.... ===========================================  
// NO RECURSION FUNCTION....



#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void sortStack(stack<int> &st) {
        
        stack<int> temp;
        int n = st.size();
        int i = 0;
        
        
        while( i < n-1 ){
            temp.push(st.top());
            st.pop();
            i++;
        }
        
        while( temp.empty() == 0 ){
            int val = temp.top();
            temp.pop();
        
            
            
            while( st.empty() == 0 && st.top() > val ){
                temp.push( st.top() );
                st.pop();
            }
            
            st.push( val );
            
        }
        
    }
};





