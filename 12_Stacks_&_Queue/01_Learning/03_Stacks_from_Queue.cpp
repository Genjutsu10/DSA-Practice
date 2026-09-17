


#include<bits/stdc++.h>
using namespace std;

class MyStack {
public:

    int s;
    queue<int> q;
    
    MyStack() {
        s = q.size();
    }
    
    void push(int x) {

        s = q.size();
        q.push(x);

        for( int i = 0 ; i < s ; i++ ){
            q.push( q.front() );
            q.pop();
        }  

    }
    
    int pop() {
        int a = q.front();
        q.pop();
        return a;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.size() == 0;
    }
};