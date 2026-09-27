//! =========================================== BRUTE CODE... ===========================================


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<int> findNSE(vector<int>& heights) {

        int n = heights.size();
        vector<int> nse(n);

        for(int i = 0; i < n; i++){

            int nextSmallerIndex = n;

            for(int j = i + 1; j < n; j++){

                if(heights[j] < heights[i]){
                    nextSmallerIndex = j;
                    break;
                }
            }

            nse[i] = nextSmallerIndex;
        }

        return nse;
    }


    vector<int> findPSE(vector<int>& heights) {

        int n = heights.size();
        vector<int> pse(n);

        for(int i = 0; i < n; i++){

            int prevSmallerIndex = -1;

            for(int j = i - 1; j >= 0; j--){

                if(heights[j] < heights[i]){
                    prevSmallerIndex = j;
                    break;
                }
            }

            pse[i] = prevSmallerIndex;
        }

        return pse;
    }


    int largestRectangleArea(vector<int>& heights) {

        int n = heights.size();

        vector<int> nse = findNSE(heights);
        vector<int> pse = findPSE(heights);

        int maxArea = 0;

        for(int i = 0; i < n; i++){

            int width = nse[i] - pse[i] - 1;

            int area = heights[i] * width;

            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};


//! =========================================== OPTIMAL CODE... ===========================================

class Solution {
public:

    int largestRectangleArea(vector<int>& heights) {

        int n = heights.size();

        stack<int> st;

        int maxArea = 0;

        // Hum n tak loop chalayenge.
        // Jab i == n hoga tab currentHeight ko 0 lenge.
        // Isse stack me bache hue saare elements
        // bahar aa jayenge.

        for (int i = 0; i <= n; i++) {

            int currentHeight;

            // i == n par array me koi actual element nahi hai.
            // Isliye uski height 0 maan rahe hai.
            // Ye 0 aate hi stack ke bache hue elements
            // pop hone lagenge.

            if (i == n) {
                currentHeight = 0;
            }
            else {
                currentHeight = heights[i];
            }

            // Jab tak current height stack ke top ki height
            // se choti nahi milti, tab tak index stack me daalte rahenge.
            //
            // Jaise hi current height choti milti hai,
            // stack ke top wale element ka rectangle
            // yahi par end ho jayega.

            while (!st.empty() && heights[st.top()] > currentHeight) {

                // Stack ke top par jis element ka index hai,
                // uska area ab calculate karenge.

                int elementIndex = st.top();

                st.pop();

                // Current element ko pop karne ke baad
                // stack ka jo top bachega
                // wahi PSE hoga.

                int pse;

                if (st.empty()) {
                    // Left side me koi smaller element nahi mila.
                    pse = -1;
                }
                else {
                    pse = st.top();
                }

                // Current index hi NSE hoga.
                // Kyuki current height stack ke top se choti hai.

                int nse = i;

                // PSE aur NSE ke beech ke saare elements
                // current height ke rectangle me aa sakte hai.
                //
                // PSE aur NSE ko include nahi karna hai.

                int width = nse - pse - 1;

                // Area = height × width

                int area = heights[elementIndex] * width;

                // Jo bhi maximum area mila hai
                // usko update karenge.

                maxArea = max(maxArea, area);
            }

            // i == n actual array ka index nahi hai.
            // Isliye n ko stack me push nahi karna.
            //
            // Baaki saare actual indices ko stack me push karenge.

            if (i < n) {
                st.push(i);
            }
        }

        return maxArea;
    }
};


/*

Jab tak current bada hai
        ↓
Index stack me daalo

Current chota mila
        ↓
Stack top ka element pop karo
        ↓
NSE = current index
        ↓
PSE = pop karne ke baad stack.top()
        ↓
Width = NSE - PSE - 1
        ↓
Area = Height × Width
        ↓
maxArea update karo

*/