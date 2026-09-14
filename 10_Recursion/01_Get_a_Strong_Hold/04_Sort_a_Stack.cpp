

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



//! =========================================== RECURSIVE FUNCTION.... ===========================================  


class Solution {
  public:
    
    void help(stack<int> &st , int value ) {
        
        if( st.empty() == 1 || value > st.top() ){
            st.push( value );
            return ;
        }
        
        int insert = st.top();
        
        st.pop();
        
        help( st , value );
        
        st.push( insert );
        
    }
  
  
  
  
    void sortStack(stack<int> &st) {
        
        
        int n = st.size();
        
        if( st.empty() == 1 ){
            return ;
        }
        
        int value = st.top();
        st.pop();
        
        sortStack( st );
        
        help ( st , value );
    }
};



