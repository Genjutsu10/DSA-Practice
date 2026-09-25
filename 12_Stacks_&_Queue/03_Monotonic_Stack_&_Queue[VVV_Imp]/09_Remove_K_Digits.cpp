
//! ========================================  Brute Force.... =========================================== 

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {

        int n = num.size();

        int i = 0;
        int count = 0;

        while( i < n-1 && count != k ){
            if( num[i] > num[i+1] ){
                num.erase( i , 1 );
                count++;
                if( i > 0 ){
                    i--;
                }
            }else{
                i++;
            }
        }

        i = 0;

        // If k digits are still left to remove
        while(count < k) {
            num.erase(num.size() - 1, 1);
            count++;
        }

        // Remove leading zeroes
        while(!num.empty() && num[0] == '0') {
            num.erase(0, 1);
        }


        if(num.empty()) {
            return "0";
        }
        return num;
    }
};


//! =========================================== OPTIMAL CODE... ===========================================

class Solution {
public:
    string removeKdigits(string num, int k) {

        stack<char> st;

        for(int i = 0; i < num.size(); i++) {

            while(!st.empty() && k > 0 && st.top() > num[i]) {
                st.pop();
                k--;
            }

            st.push(num[i]);
        }

        // If k digits are still remaining
        while(k > 0) {
            st.pop();
            k--;
        }

        // converting stack into queue..
        string ans = "";

        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        // Remove leading zeroes
        int i = 0;

        while(i < ans.size() && ans[i] == '0') {
            i++;
        }

        ans = ans.substr(i);

        if(ans.empty())
            return "0";

        return ans;
    }
};


