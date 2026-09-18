//! ========================================  Brute Force.... =========================================== 
 

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int> arr) {

        int n = arr.size();

        vector<int> original = arr;

        if( n == 1){
            arr[0] = -1;
            return arr;
        }

        for (int i = 0; i < n; i++) {

            for (int j = i + 1; j < i + n; j++) {

                int index = j % n;

                if (arr[i] < original[index]) {
                    arr[i] = original[index];
                    break;
                }

                if (j == i + n - 1) {
                    arr[i] = -1;
                }
            }
        }

        return arr;
    }
};        



//! =========================================== OPTIMAL CODE... ===========================================





