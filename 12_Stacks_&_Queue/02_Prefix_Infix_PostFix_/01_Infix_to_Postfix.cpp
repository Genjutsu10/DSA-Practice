/*

! if the a->b transformation is there so starting i depends on A..
? check A if starting ( i = 0) he have the operator start from (i = n-1) and Visca Barca..


*/



#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Give priority to every operator
    int priority(char c) {

        if(c == '^')
            return 3;

        if(c == '*' || c == '/')
            return 2;

        if(c == '+' || c == '-')
            return 1;

        return -1;
    }

    string infixToPostfix(string& s) {

        stack<char> st;
        string ans;

        int i = 0;
        int n = s.size();

        while(i < n) {

            // If it is an operand, directly add it to ans
            if((s[i] >= 'a' && s[i] <= 'z') ||
               (s[i] >= 'A' && s[i] <= 'Z') ||
               (s[i] >= '0' && s[i] <= '9')) {

                ans += s[i];
            }

            // If '(' comes, simply push it into the stack
            else if(s[i] == '(') {

                st.push(s[i]);
            }

            // If ')' comes, pop operators until '(' is found
            else if(s[i] == ')') {

                while(!st.empty() && st.top() != '(') {

                    ans += st.top();
                    st.pop();
                }

                // Remove '(' from the stack
                st.pop();
            }

            // If it is an operator
            else {

                /*
                    If the incoming operator has lower priority
                    than st.top(), pop st.top() and add it to ans.

                    If both have the same priority, pop the top
                    for left-associative operators (+,-,*,/).

                    But for '^', do not pop when priorities are equal
                    because '^' is right-associative.
                */
                while(!st.empty() && st.top() != '(') {

                    if(priority(s[i]) < priority(st.top())) {
                        ans += st.top();
                        st.pop();
                    }
                    else if(priority(s[i]) == priority(st.top()) && s[i] != '^') {
                        ans += st.top();
                        st.pop();
                    }
                    else {
                        break;
                    }
                }

                // After removing higher/equal priority operators,
                // push the current operator into the stack
                st.push(s[i]);
            }

            i++;
        }

        // At the end, pop all remaining operators into ans
        while(!st.empty()) {

            ans += st.top();
            st.pop();
        }

        return ans;
    }
};

/*


a+b*(c^d-e)

|   i | Element | Stack (`st`) | `ans`       |
| --: | :-----: | :----------- | :---------- |
|   0 |   `a`   | —            | `a`         |
|   1 |   `+`   | `+`          | `a`         |
|   2 |   `b`   | `+`          | `ab`        |
|   3 |   `*`   | `+ *`        | `ab`        |
|   4 |   `(`   | `+ * (`      | `ab`        |
|   5 |   `c`   | `+ * (`      | `abc`       |
|   6 |   `^`   | `+ * ( ^`    | `abc`       |
|   7 |   `d`   | `+ * ( ^`    | `abcd`      |
|   8 |   `-`   | `+ * ( -`    | `abcd^`     |
|   9 |   `e`   | `+ * ( -`    | `abcd^e`    |
|  10 |   `)`   | `+ *`        | `abcd^e-`   |
| End |    —    | —            | `abcd^e-*+` |





1. Sabse pehle operators ko stack mein daalo.

2. Operator ko stack mein tab tak daalo
   jab tak incoming operator ki priority
   st.top() se kam na ho jaye.

3. Agar incoming operator ki priority
   st.top() se kam ho jaye,
   to st.top() ko ans mein daalo aur pop karo.

4. Fir incoming operator ko stack mein push karo.

5. Agar '(' aaye, to use directly stack mein push karo.

6. Agar ')' aaye, to operators ko stack se
   ans mein daalte jao jab tak '(' na mil jaye.

7. '(' milne par use stack se pop kar do.

8. Expression khatam hone ke baad,
   stack mein bache hue saare operators ko
   ans mein daal do.






*/

