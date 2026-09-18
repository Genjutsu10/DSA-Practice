/*

!  Prefix → Postfix

1. Start from i = n-1 and scan from right to left.( at the i = 0 there are operators..)
2. If operand comes → push it into the stack.
3. If operator comes → take top1 then top2, then: 
?                                               str = top1 + top2 + operator

! ex.
! Stack: F, E, D
  top1 = D
  top2 = E
  str = D + E + '+'
      = DE+
! stack: F, DE+

? Whole Example is at the end...

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string preToPost(string pre_exp) {

        stack<string> st;

        // Scan from right to left
        for(int i = pre_exp.size() - 1; i >= 0; i--) {

            // If operand, push into stack
            if((pre_exp[i] >= 'a' && pre_exp[i] <= 'z') ||
               (pre_exp[i] >= 'A' && pre_exp[i] <= 'Z') ||
               (pre_exp[i] >= '0' && pre_exp[i] <= '9')) {

                st.push(string(1, pre_exp[i]));
            }

            // If operator
            else {

                string top1 = st.top();
                st.pop();

                string top2 = st.top();
                st.pop();

                string temp = top1 + top2 + pre_exp[i];

                st.push(temp);
            }
        }

        return st.top();
    }
};


//! Ex. /-AB*+DEF
    
//     |  i  | Element | `st`          |
//     |     |         |               |
//     |   0 |   `F`   | `F`           |
//     |   1 |   `E`   | `F, E`        |
//     |   2 |   `D`   | `F, E, D`     |
//     |   3 |   `+`   | `F, DE+`      |
//     |   4 |   `*`   | `DE+F*`       |
//     |   5 |   `B`   | `DE+F*, B`    |
//     |   6 |   `A`   | `DE+F*, B, A` |
//     |   7 |   `-`   | `DE+F*, AB-`  |
//     |   8 |   `/`   | `AB-DE+F*/`   |


