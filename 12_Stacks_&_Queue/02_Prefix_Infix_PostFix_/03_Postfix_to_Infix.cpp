/*

Postfix → Infix
Operand (A) goes into the stack.
If an operator comes → take the last two elements from the stack, put the operator between them, and put brackets () around the expression.

! Please read the last paragraph for better understanding...

*/


#include<bits/stdc++.h>
using namespace std;


class Solution {
	public:
	string postToInfix(string &s) {
	    
	    stack<string>st;
	    int i = 0;
	    int n = s.size();
	    string conc;
		
		while (i < n) {
			if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9')) {
				
				st.push( string(1 , s[i] ) );   // string name(length, character);
			}else{
			    
			    string t1 = st.top();
			    st.pop();
			    
			    string t2 = st.top();
			    st.pop();
			    
			    conc = '('+ t2 + s[i] + t1 + ')';
			    st.push( conc );
			    
			}
			
			i++;
		
		}
		return st.top();
		
	}
};




/*


ex.  AB-DE+F*

|  i  | Element | Stack ( of string )  |
| --: | :-----: | :------------------- |
|   0 |    A    | `A`                  |
|   1 |    B    | `A, B`               |
|   2 |    -    | `(A-B)`              |
|   3 |    D    | `(A-B), D`           |
|   4 |    E    | `(A-B), D, E`        |
|   5 |    +    | `(A-B), (D+E)`       |
|   6 |    F    | `(A-B), (D+E), F`    |
|   7 |    *    | `((A-B), ((D+E)*F))` |


ANS :  ((A-B), ((D+E)*F)) ....


!  MAIN POINTS...

so ekandarit kya kr rhe ki ek stack banaya string ka aur usme ek ek string of operands dal rhe,
lekin jb operator mila tb jo stack ke last 2 elements hai uske bich mai operator dal rhe fir usko as a 1 string bolke stack mai dal rhe...(last 2 element + operator) as a one string...

aur hame pta hai ki hamara input valid haii to aakhir tk sb string jo ki stack mai dale hai vo ek bn jayenge...
so hum phir return karenge stack.top()...


*/