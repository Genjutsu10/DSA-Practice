//! ========================================  Brute Force.... =========================================== 
 
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> nextSmallerEle(vector<int>& arr) {
        
        
        int n = arr.size();
        
        for( int i = 0; i < n; i++ ){
            for( int j = i+1; j < n; j++ ){
                if( arr[i] > arr[j]){
                    arr[i] = arr[j];
                    break;
                }
                if( j == n-1 ){
                    arr[i] = -1;
                }
            }
        }
        
        arr[n-1] = -1;
        return arr;
        
    }
};



//! =========================================== OPTIMAL CODE... ===========================================

class Solution {
  public:
    vector<int> nextSmallerEle(vector<int>& arr) {
        
        
        int n = arr.size();
        
        stack<int>st;
        int a;
        
        for( int i = n-1; i >= 0; i-- ){
            
            while( !st.empty() && arr[i] <= st.top() ){   // agar number repeat krr rhe hai to 2,2 hai to '2' ka nse is not 2 so arr[i] == st.top() hua to bhi pop(); 
                st.pop();
            }
            a = arr[i];
            
            if( st.empty() ){
                arr[i] = -1;
            }
            else{
                arr[i] = st.top();
            }
            
            st.push(a);
        }
        return arr;
        
    }
};