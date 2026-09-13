

//! =========================================== RECURSIVE FUNCTION.... ===========================================  
// RECURSION FUNCTION....



#include<bits/stdc++.h>
using namespace std;


class Solution {
  public:
  
    void insertStack(stack<int> &st , int value ){
        
        if( st.empty() == 1 ){
            st.push( value );
            return;
        }
        
        int insert = st.top();
        st.pop();
        
        insertStack( st , value );
        
        st.push( insert );
        
    }
    
    void reverseStack(stack<int> &st) {
        
        if ( st.empty() == 1 ){
            return;
        }
        
        int value = st.top();
        st.pop();
        
        reverseStack ( st );
        
        insertStack ( st , value );
        
    }
};