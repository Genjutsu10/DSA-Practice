//?      NOT BRUTE BUT LENGHTYY METHOD....


// class Solution {
//   public:
//     int getSecondLargest(vector<int> &arr) {
        
//         int max = arr[0];
//         int n = arr.size();
        
//         for (int i=0; i<n; i++){
//             if( max<=arr[i]){
//                 max = arr[i];
//             }
//         }
        
//         int secmax;
//         int count = 0;
        
//         for (int i=0; i<n; i++){
//             if(max != arr[i]){
//                 secmax = arr[i];
//                 count++;
//             }
            
//         }
//         if( count == 0 ){
//             return -1;
//         }
        
        
//         for(int i=0; i<n; i++){
//             if( max > arr[i] && arr[i] > secmax){
//                 secmax = arr[i];
//             }
//         }
//         return secmax;
//     }
// };


//! =========================================== OPTIMAL CODE... ===========================================

#include <bits/stdc++.h>
using namespace std;

int SecondLargest(vector<int> &arr) {
    int max = arr[0], smax = -1;

    for (int i = 0; i < arr.size(); i++) {

        if (arr[i] > max) {
            smax = max;
            max = arr[i];
        }
        else if (arr[i] > smax && arr[i] != max) {
            smax = arr[i];
        }
    }

    return smax;
}

int main() {

    vector<int> arr = {5, 2, 8, 3, 6};

    cout << SecondLargest(arr);

    return 0;
}












