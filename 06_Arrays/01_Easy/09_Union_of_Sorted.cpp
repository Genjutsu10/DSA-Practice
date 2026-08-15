

//! =========================================== OPTIMAL CODE... ===========================================
//!                                        Two Pointer method....

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        int n = a.size();
        int m = b.size();
        
        int i = 0;
        int j = 0;
        
        vector<int> res;
        
        while( i < n && j < m ){
            if( a[i] <= b[j] ){
                if( res.size() == 0 || res.back() != a[i] ){  // res.size() == 0 is liye kyuki start mai res khali hai to jo bhi aa jayega andar ayega and we dont know any about the a[i] bada hai ya b[j] any.. 
                    res.push_back(a[i]);                      // res.back()  apne ko last element of the res jo insert kiya hai wo dega...
                }                                             
                i++;                                          
            } else if( a[i] >= b[j] ){                        // agar koi bhi 2 sorted array tum lo usse union kro to pta chalega arr[i]>=arr[i+1] ALWAYS....
                if( res.size() == 0 || res.back() != b[j] ){  // aur is liye i ko i-1 ke saath compare karenge koyki humne 2 sort arrays ko union kr rhe haii...
                    res.push_back(b[j]);                      // back to back 3 same bhi aa gye to bhi farak nhi padega...
                }
                j++;
            }
        }
        
        while(i<n){
            if( res.size() == 0 || res.back() != a[i] ){
                res.push_back(a[i]);
            }
            i++;
        }
        
        while(j<m){
            if( res.size() == 0 || res.back() != b[j] ){
                res.push_back(b[j]);
            }
            j++;
        }
        
        return res;
    }
};





