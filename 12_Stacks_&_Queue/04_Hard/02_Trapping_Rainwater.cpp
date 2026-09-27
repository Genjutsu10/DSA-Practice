
//! =========================================== OPTIMAL CODE... ===========================================

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int trap(vector<int>& height) {

        int n = height.size();

        vector<int> prefixm(n);
        vector<int> suffixm(n);


        // Prefix maximum:
        // Har index ke left side me jo maximum height hai
        // usko prefixm[i] me store karenge.
        //
        // Example:
        //
        // height  = [4, 2, 0, 3, 2, 5]
        // prefix  = [4, 4, 4, 4, 4, 5]
        //
        // prefixm[i] = max height from LEFT till i


        prefixm[0] = height[0];

        for(int i = 1; i < n; i++){

            prefixm[i] = max(height[i], prefixm[i-1]);
        }


        // Suffix maximum:
        // Har index ke right side me jo maximum height hai
        // usko suffixm[i] me store karenge.
        //
        // suffixm[i] = max height from RIGHT till i


        suffixm[n-1] = height[n-1];

        for(int j = n-2; j >= 0; j--){

            suffixm[j] = max(height[j], suffixm[j+1]);
        }


        // Ab har index par check karenge ki water store ho
        // sakta hai ya nahi.

        // Agar current height se:
        // left maximum bhi bada hai,
        // AND
        // right maximum bhi bada hai...

        // tabhi yaha water store hoga.


        int result = 0;

        for(int k = 0; k < n; k++){

            if(height[k] < prefixm[k] && height[k] < suffixm[k]){

                // Water level depend karega:
                //
                // min(left maximum, right maximum)
                //
                // kyuki water choti boundary tak hi store
                // ho sakta hai.
                //
                // Water stored =
                //
                // min(leftMax, rightMax) - currentHeight

                result = result + min( prefixm[k], suffixm[k] ) - height[k];
            }
        }

        return result;
    }
};


//! =========================================== WITHOUT ANY COMMENTS CODE... ===========================================


// class Solution {
// public:
//     int trap(vector<int>& height) {
        
//         int n = height.size();

//         vector<int> prefixm(n);
//         vector<int> suffixm(n);

//         prefixm[0] = height[0];
//         for( int i = 1; i < n; i++ ){
//             prefixm[i] = max( height[i] , prefixm[i-1] );
//         }

//         suffixm[n-1] = height[n-1];
//         for( int j = n-2; j >= 0; j-- ){
//             suffixm[j] = max( height[j] , suffixm[j+1] );

//         }

//         int result = 0;

//         for( int k = 0; k < n; k++ ){

//             if( height[k] < prefixm[k] && height[k] < suffixm[k] ){
//                 result = result + min( prefixm[k] , suffixm[k] ) - height[k] ;
//             }
    
//         }
//         return result;        
//     }
// };