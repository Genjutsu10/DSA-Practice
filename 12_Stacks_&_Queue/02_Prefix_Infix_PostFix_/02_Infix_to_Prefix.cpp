/*


! Infix → Prefix

Reverse the infix expression.
Convert the reversed expression into postfix.
(under the required conditions)
Reverse the postfix answer.

→ This gives the prefix expression.

? example given in the end.....

*/



#include<bits/stdc++.h>
using namespace std;


class Solution {
public:

    int priority(char c) {
        if(c == '^') return 3;
        if(c == '*' || c == '/') return 2;
        if(c == '+' || c == '-') return 1;
        return -1;
    }

    string infixToPrefix(string s) {

        // Step 1: Reverse the expression
        reverse(s.begin(), s.end());

        // Step 2: Swap '(' and ')'
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(')
                s[i] = ')';
            else if(s[i] == ')')
                s[i] = '(';
        }

        stack<char> st;
        string ans;

        // Step 3: Convert reversed expression to postfix
        for(int i = 0; i < s.size(); i++) {

            if((s[i] >= 'a' && s[i] <= 'z') ||
               (s[i] >= 'A' && s[i] <= 'Z') ||
               (s[i] >= '0' && s[i] <= '9')) {

                ans += s[i];
            }

            else if(s[i] == '(') {
                st.push(s[i]);
            }

            else if(s[i] == ')') {

                while(!st.empty() && st.top() != '(') {
                    ans += st.top();
                    st.pop();
                }

                st.pop();
            }

            else {

                while(!st.empty() && st.top() != '(') {

                    if(priority(s[i]) < priority(st.top())) {
                        ans += st.top();
                        st.pop();
                    }
                    else if(priority(s[i]) == priority(st.top()) && s[i] == '^') {
                        ans += st.top();
                        st.pop();
                    }
                    else {
                        break;
                    }
                }

                st.push(s[i]);
            }
        }

        // Step 4: Empty remaining operators
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }

        // Step 5: Reverse postfix to get prefix
        reverse(ans.begin(), ans.end());

        return ans;
    }
};

/*

ex.(A+B)*C-D+F

! Step 1: Reverse + swap brackets

 Original : (A+B)*C-D+F
 Reverse  : F+D-C*)B+A(
 Swap     : F+D-C*(B+A)


 ! Step 2: Convert to Postfix

|  i  | Element |  st     |  ans        |

|   0 |    F    |         |  F          |
|   1 |    +    |  +      |  F          |
|   2 |    D    |  +      |  FD         |
|   3 |    -    |  +-     |  FD         |
|   4 |    C    |  +-     |  FDC        |
|   5 |    *    |  +-*    |  FDC        |
|   6 |    (    |  +-*(   |  FDC        |
|   7 |    B    |  +-*(   |  FDCB       |
|   8 |    +    |  +-*(+  |  FDCB       |
|   9 |    A    |  +-*(+  |  FDCBA      |
|  10 |    )    |  +-*    |  FDCBA+     |

| End |         |         |  FDCBA+*-+  |


! Step 3: Reverse ans








*/