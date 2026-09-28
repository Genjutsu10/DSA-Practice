//! ================================== Brute code ==================================


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int celebrity(vector<vector<int>> &M) {

        int n = M.size();

        for(int i = 0; i < n; i++) {

            bool iCelebrity = true;

            for(int j = 0; j < n; j++) {

                if(i == j) {
                    continue;
                }

                if(M[i][j] == 1) {
                    iCelebrity = false;
                    break;
                }

                if(M[j][i] == 0) {
                    iCelebrity = false;
                    break;
                }
            }

            if(iCelebrity) {
                return i;
            }
        }

        return -1;
    }
};


//! ================================== Optimal code ==================================

#include <vector>
using namespace std;

int celebrity(vector<vector<int>>& mat) {

    int n = mat.size();
    int top = 0;
    int down = n - 1;

    // Step 1: Elimination to find the potential celebrity
    while (top < down) {
        if (mat[top][down] == 1) {   // btw 1 nd 3 are top nd down 
            top++;                  // imagine like[1][3] 1 -> 3 ko janta haii to row 1 cannot be celibrity so go down..

        } else if (mat[down][top] == 1) {  
            down--;                 // imagine like[3][1] 3 -> 1 ko janta haii to row 3 cannot be celibrity so go upp..

        } else {
            top++;    // agar [1][3] ko aur [3][1] ko nhi jante... 
            down--;   // iska mtlab ye ki dono celeb nhii hai kyoki celeb ko sb jante lekin 1 ko 3 nhi jaan rha aur 3 ko 1 nhi jaan rha...
        }
    }

    if (top > down) return -1;


    // Step 2: Verification of the potential candidate
    for (int i = 0; i < n; i++) {
        if (i == top) continue; // Skip diagonal element

        // Celebrity must know no one (mat[top][i] == 0) 
        // and everyone must know celebrity (mat[i][top] == 1)
        if (mat[top][i] == 1 || mat[i][top] == 0) {
            return -1;
        }
    }

    return top;
}