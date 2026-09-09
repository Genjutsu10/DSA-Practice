
// =========================================== Striver Question.. ===========================================



//! =========================================== Brute Force.... ===========================================  



#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int pascalTriangleI(int r, int c) {


        vector<vector<int>> arr( r,vector<int>(r,0) );
        arr[0][0] = 1;

        for( int i = 1 ; i < r ; i++ ){
            for( int j = 0 ; j <= i ; j++ ){

                if( j == 0 || j == i ){
                    arr[i][j] = 1;
                }else{
                    arr[i][j] = arr[i-1][j] + arr[i-1][j-1];
                }
            }
        }

        return arr[r-1][c-1];

    }
};

//! =========================================== Better condition .... =========================================== 

class Solution {
public:

    int fact(int n) {
        if(n == 0)
            return 1;

        return n * fact(n - 1);
    }

    int pascalTriangleI(int r, int c) {

        // r and c are 1-based, so convert to 0-based
        r--;
        c--;

        return fact(r) / (fact(c) * fact(r - c));
    }
};



//! =========================================== Optimal condition .... =========================================== 

class Solution {
public:
    int pascalTriangleI(int r, int c) {

        r--;
        c--;

        if(c > r - c)
            c = r - c;

        int result = 1;

        for(int i = 1; i <= c; i++) {
            result = result * (r - i + 1) / i;
        }

        return result;
    }
};




// =========================================== Leetcode Question.. ===========================================
// ====================================== Print the Pascal's triangle ========================================

//! =========================================== Optimal Code.... =============================================



class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> generate;
        generate.push_back({1});


        for( int i = 1 ; i < numRows ; i++ ){

            vector<int> row;

            for ( int j = 0 ; j <= i ; j++ ){

                if( j == 0 || j == i ){
                    row.push_back( 1 );
                }else{
                    row.push_back(generate[i-1][j-1] + generate[i-1][j]);
                }
            }
            generate.push_back({row});
        }
        return generate;
    }
};




//===================================== Print the nth row.=====================================

class Solution {
public:
    // Function to generate the Nth row of Pascal's Triangle
    vector<long long> getNthRow(int N) {
        // Result vector to store the row
        vector<long long> row;
        
        // First value of the row is always 1
        long long val = 1;
        row.push_back(val);
        
        // Compute remaining values using the relation:
        // C(n, k) = C(n, k-1) * (n-k) / k
        for (int k = 1; k < N; k++) {
            val = val * (N - k) / k;
            row.push_back(val);
        }
        
        return row;
    }
};

