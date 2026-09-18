/*
!  Postfix → Prefix

1. Read the postfix expression from left to right...
2. If an operand comes → push it into the stack...
3. If an operator comes → take the top two elements, put the operator before them, and push the new expression back into the stack...

*/


#include<bits/stdc++.h>
using namespace std;


class Solution {
  public:
    string postToPre(string s) {
        
        stack<string> st;

        for(int i = 0; i < s.size(); i++) {

            // If operand, push it into stack
            if(( s[i] >= 'a' && s[i] <= 'z') ||
               ( s[i] >= 'A' && s[i] <= 'Z') ||
               ( s[i] >= '0' && s[i] <= '9')) {

                st.push(string(1, s[i]));
            }

            // If operator
            else {

                string a = st.top();
                st.pop();

                string b = st.top();
                st.pop();

                string temp = s[i] + b + a;

                st.push(temp);
            }
        }

        return st.top();
    }
};

/*

! ex. AB-DE+F*/

/*

|  i  | Element | `st`          |
| --: | :-----: | :------------ |
|   0 |   `A`   | `A`           |
|   1 |   `B`   | `A, B`        |
|   2 |   `-`   | `-AB`         |
|   3 |   `D`   | `-AB, D`      |
|   4 |   `E`   | `-AB, D, E`   |
|   5 |   `+`   | `-AB, +DE`    |
|   6 |   `F`   | `-AB, +DE, F` |
|   7 |   `*`   | `-AB, *+DEF`  |
|   8 |   `/`   | `/-AB*+DEF`   |


! ANS : /-AB*+DEF



*/





