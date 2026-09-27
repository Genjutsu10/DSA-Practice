
//! =========================================== OPTIMAL CODE... ===========================================

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int largestRectangleArea(vector<int>& heights) {

        int n = heights.size();
        stack<int> st;
        int maxArea = 0;

        for (int i = 0; i <= n; i++) {
            // Treat the element past the array end as height 0 to flush remaining stack elements
            int currentHeight = (i == n) ? 0 : heights[i];

            while (!st.empty() && heights[st.top()] > currentHeight) {
                int elementIndex = st.top();
                st.pop();

                int pse = st.empty() ? -1 : st.top();
                int nse = i;

                int width = nse - pse - 1;
                int area = heights[elementIndex] * width;

                maxArea = max(maxArea, area);
            }

            st.push(i);
        }

        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();

        int Maxarea = 0;

        vector<int> height(m , 0);

        for( int i = 0 ; i < n ; i++ ){
            for( int j = 0; j < m; j++ ){
                if( matrix[i][j] == '1' ){
                    height[j]++;
                }else{
                    height[j] = 0;
                }
            }
            int area = largestRectangleArea( height );
            Maxarea = max( Maxarea , area );
        }
        return Maxarea;

    }
};