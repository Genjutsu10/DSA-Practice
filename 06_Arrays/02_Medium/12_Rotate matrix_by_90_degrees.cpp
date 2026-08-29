

//! ====================================== Brute Force ========================================
//* Time Complexity = O(n^2) 
//* Space Complexity = O(n^2)



#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> res(n , vector<int>(n));

        for ( int i = 0; i < n; i++ ){
            for ( int j = 0; j < m; j++ ){
                res[j][n-i-1] = matrix[i][j] ;
            }
        }
        matrix = res;
    }
};



//! =========================================== OPTIMAL CODE... ===========================================


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();

        for ( int i = 0; i < n; i++ ){
            for ( int j = 0; j < m; j++ ){
                if( i > j ){
                    swap( matrix[j][i] , matrix[i][j] ) ;
                }
            }
        }
        for( int i = 0 ; i < n ; i++ ){
            reverse(matrix[i].begin(),matrix[i].end());
        }
        
    }
};
