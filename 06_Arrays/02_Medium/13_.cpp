#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> res;

        int left = 0;
        int top = 0;

        int right = m - 1;
        int bottom = n - 1;

        while( top <= bottom && left <= right ){

            for (int j = left; j <= right; j++ ){     // left to right
                res.push_back( matrix[top][j] );
            }
            top++;

            
            for(int i = top; i <= bottom; i++ ){
                res.push_back( matrix[i][right] );    // up to down
            }
            right--;


            if (top <= bottom){
                for( int j = right; j >= left; j-- ){
                    res.push_back( matrix[bottom][j] );  // right to left
                }
                bottom--;
            }
            

            if ( left <= right ){
                for ( int i = bottom ; i >= top; i-- ){
                    res.push_back( matrix[i][left] );     // doen to up
                }
            left++;
            }
            
        }

        return res;
    }
};