/*
    Here, we cannot use the same method as the previous question.

    Take a stack like:
    Top -> 1, 2, 3
           [1, 2, 3]

    Now, if we want to push 4 at the bottom, simply using the
    previous method will give:

    Top -> 4, 1, 2, 3

    But this is not what we want.

    We need:
    Top -> 1, 2, 3, 4

    Also, we cannot simply use a loop from the top to the next
    element to solve this.

    Therefore, we need a different approach here.
*/

#include<bits/stdc++.h>
using namespace std;

class MyQueue {
public:

    stack<int>st1,st2;

    MyQueue() {

    }
    
    void push(int x) {
        st1.push(x);  // jo bhi ele aayega usko kro stack1 mai push..
    }
    
    // agar pop krna hai to sb elements ko stack2 mai upload kro...
    int pop() {   
        if(st2.empty()) { // stack 2 emoty hai ky dekho
            while(!st1.empty()) { // agar hai to stack 1 ke sab ele stack 2 mai upload kroo..
                st2.push(st1.top());
                st1.pop();
            }
        }

        int a = st2.top();// agar stack 2 empty bhi nhi hai to uska element pop kro agar nahi hai to uper ke while se usme dalo phir pop kro..
        st2.pop();
        return a;
    }
    
    int peek() {
        if(st2.empty()) {
            while(!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }
        }

        return st2.top();
    }
    
    bool empty() {

        return ( st1.empty() && st2.empty() );
        
    }
};