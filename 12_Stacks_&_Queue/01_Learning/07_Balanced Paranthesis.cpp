#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    stack<char> st;

    bool isValid(string s) {

        int i = 0;
        while (i < s.size()) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]);
                i++;
            } else {

                if (st.size() == 0)
                    return false;

                if ((s[i] == ')' && st.top() == '(') ||
                    (s[i] == '}' && st.top() == '{') ||
                    (s[i] == ']' && st.top() == '[')) {
                    st.pop();
                } else {
                    return false;
                }
                i++;
            }
        }
        return (st.size() == 0);
        
    }
};