
//! =========================================== BRUTE CODE... ===========================================

#include<bits/stdc++.h>
using namespace std;

class MinStack {
public:
    stack<int> st;
    stack<int> temp;

    MinStack() {}

    void push(int value) { st.push(value); }

    void pop() { st.pop(); }

    int top() { return st.top(); }

    int getMin() {
        if (st.size() == 1) {
            return st.top();
        }
        int min = st.top();
        temp.push(st.top());
        st.pop();

        while (st.size() != 0) {
            if (st.top() < min) {
                min = st.top();   
            }
            temp.push(st.top());
            st.pop();
        }
        while( temp.size() != 0 ){
            st.push( temp.top() );
            temp.pop();
        }
        return min;
    }
};


//! =========================================== OPTIMAL CODE... ===========================================

class MinStack {
public:
    stack<int> st;
    stack<int> temp;

    MinStack() {
    }

    void push(int value) {
        if( st.size() == 0 ){
            st.push(value);
            temp.push(value);
        }else{
            st.push(value);
            if( st.top() <= temp.top() ){
                temp.push(st.top());
            }
        }
    }

    void pop() {
        if( st.top() == temp.top() ){
            temp.pop();
        }
        st.pop(); 
    }

    int top() {
        return st.top(); 
    }

    int getMin() {
        return temp.top();
    }
};