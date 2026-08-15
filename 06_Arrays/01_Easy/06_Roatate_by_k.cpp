

//! =========================================== Brute Force.... ===========================================



#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void rotateclockwise(vector<int>& arr, int k) {
        int n = arr.size();
        
        k = k % n; // Agar k n se he bada ho to n=5,k=7 ghum ghuma ke "k" k=2 p
        
        vector <int> res;
        
        
        for(int i=n-k; i<=n-1; i++){
            res.push_back(arr[i]);
        }
        
        for ( int i=n-1 ; i>=k; i-- ){
            arr[i] = arr[i-k];
        }
        
        for(int i=0; i<k; i++){
            arr[i]=res[i];
        }
    }
};


//! =========================================== OPTIMAL CODE... ===========================================


#include<bits/stdc++.h>
using namespace std;

void reverse(vector<int>&arr ,int low  ,int max ){
    while( low < max){
        swap(arr[low],arr[max]);
        low++;
        max--;
    }
}


void rotateclockwise(vector<int>& arr, int k) {
        int n = arr.size();
        
        k = k % n;
        
        if( k==0 ) return ;
        
        
        
        reverse( arr, 0 , k-1 );
        reverse( arr, k , n-1 );
        reverse( arr, 0, n-1 );
        
    }

int main(){
    
    vector<int> arr = {3, 5, 1, 8, 2};
    rotateclockwise(arr,3);

    for(auto it:arr){
        cout<<it;
    }

    return 0;
}


