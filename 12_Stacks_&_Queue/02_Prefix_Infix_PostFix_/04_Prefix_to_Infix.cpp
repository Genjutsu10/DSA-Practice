/*

Prefix → Infix
Scan the prefix expression from right to left.
If an operand comes, directly push it into the stack.
If an operator comes, take the last two elements from the stack, put the operator between them, add brackets ( ), and push the new expression back into the stack.

same like the postfix --> infix just the iteration is from the last i = n-1;  and  
there we take top1 amd then top2 and ( top2 ,something, top1) but here (top1 ,someting, top2)...


*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
  public:
    string preToInfix(string &s) {
        
        stack<string> st;
        int n = s.size();
        int i = n-1;
        
        while( i >= 0 ){
            
            if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9')) {

				st.push( string(1 , s[i] ) );   // string name(length, character);
			}else{
			    
			    string s1 = st.top();
			    st.pop();
			    
			    string s2 = st.top();
			    st.pop();
			    
			    string conc = '(' + s1 + s[i] + s2 + ')';
			    st.push( conc );
			}
			i--;
            
        }
        return st.top();
        
    }
};



/*

ex. *+PQ-MN

! Step 1 :

Scan the prefix expression from right to left.
? * + P Q - M N



! Step 2 & 3 — Stack Table :

|  i  | Element |  st (of string) |
| --: | :-----: | :-------------- |
|   0 |    N    | `N`             |
|   1 |    M    | `N, M`          |
|   2 |    -    | `(M-N)`         |
|   3 |    Q    | `(M-N), Q`      |
|   4 |    P    | `(M-N), Q, P`   |
|   5 |    +    | `(M-N), (P+Q)`  |
|   6 |    *    | `((M-N)*(P+Q))` |

! ANS : ((M-N)*(P+Q))
            


*/

