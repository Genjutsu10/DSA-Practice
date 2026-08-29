

//! ====================================== Brute Force ========================================
//* Time Complexity = O(m x n x (m+n)) 
//* Space Complexity = O(m+n)




#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        vector<int> col;
        vector<int> row;

        int n = matrix.size();
        int m = matrix[0].size();

        for( int i = 0 ; i < n ; i++ ){
            for( int j = 0 ; j < m ; j++ ){

                if( matrix[i][j] == 0 ){
                    col.push_back(j);
                    row.push_back(i);
                }
            }
        }
        for( auto x : col){
            for( int i = 0 ; i < n ; i++ ){
                matrix[i][x] = 0;
            }
        }

        for( auto y : row){
            for( int j = 0 ; j < m ; j++ ){
                matrix[y][j] = 0;
            }
        }
    }
};


//! ====================================== Better Force ========================================

// Time Complexity: O(m × n)
// Space Complexity: O(m + n)


class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> col(m,0);
        vector<int> row(n,0);

        for( int i =0 ; i < n ; i++ ){
            for ( int j = 0; j < m ; j++ ){
                if( matrix[i][j] == 0 ){
                    col[j] = 1;    // ye yaad rakhnge ki konsa row ya column ko 0 banana haii..
                    row[i] = 1;    // samjho ki j=2 pe aaya 0 to col[2]=1 hoga aur phir usko as a boolean use krenge niche..
                }
            }
        }

        for( int i =0 ; i < n ; i++ ){
            for ( int j = 0; j < m ; j++ ){
                if( col[j] || row[i] ){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};




//! =========================================== OPTIMAL CODE... ===========================================


//! ====================================== Optimal ========================================
//* Time Complexity = O(m x n)
//* Space Complexity = O(1)

/*


isme jo pehla row and column hota hai use pehle nhi lete 
sirff jo baki bacha use 0 banate phir baadme 1st row nd column ko 0 banate accordinglyy
aur jo arr[1][1] hota haii use as acolumn lo aur row mai uski jagah arr[1][0] lo joki exist he nhi krta...


*/ 

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();

        int col0 = 1;

        // Use first row and first column as markers
        for(int i = 0; i < n; i++){

            for(int j = 0; j < m; j++){

                if(matrix[i][j] == 0){

                    // Mark the row
                    matrix[i][0] = 0;

                    // Mark the column
                    if(j != 0)
                        matrix[0][j] = 0;
                    else
                        col0 = 0;
                }
            }
        }

        // Set inner matrix to zero using markers
        for(int i = 1; i < n; i++){

            for(int j = 1; j < m; j++){

                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }

        // Handle first row
        if(matrix[0][0] == 0){

            for(int j = 0; j < m; j++){
                matrix[0][j] = 0;
            }
        }

        // Handle first column
        if(col0 == 0){

            for(int i = 0; i < n; i++){
                matrix[i][0] = 0;
            }
        }
    }
};











