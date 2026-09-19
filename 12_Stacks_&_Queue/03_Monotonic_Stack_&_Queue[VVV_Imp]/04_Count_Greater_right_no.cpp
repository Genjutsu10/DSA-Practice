//! ========================================  Brute Force.... =========================================== 


/*

    First loop indices ke upar chalega because hume sirf
    wahi positions ka answer chahiye jo indices me diye hai.

    So:

        k = 0
        i = indices[k]

    Now i is the actual index in arr jiska answer
    hume find karna hai.

    Then second loop i + 1 se n tak chalega because
    hume sirf i ke right side ke elements check karne hai.

    Example:

        arr     = [1, 3, 2, 5, 4]
        indices = [1, 3]

        k = 0
        i = indices[0] = 1

        Now check: arr[1] with..

        j = i + 1 = 2 → arr[2]
        j = 3          → arr[3]
        j = 4          → arr[4]

        Then:

        k = 1
        i = indices[1] = 3

        Now check:
        j = i + 1 = 4 → arr[4]

    So first loop decides:
        "Kis index ka answer chahiye?"

    And second loop decides:
        "Us index ke right me kitne greater elements hain?"

*/
 
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> countGreater(vector<int> &arr, vector<int> &indices) {

        int n = arr.size();
        int s = indices.size();
        
        for( int k = 0; k < s; k++ ){
            
            int i = indices[k];
            int count = 0;
            
            for( int j = i+1; j < n ; j++ ){
                if( arr[i] < arr[j] ){
                    count++;
                }
            }
            
            indices[k] = count;
        }
        return indices;
    }
};






