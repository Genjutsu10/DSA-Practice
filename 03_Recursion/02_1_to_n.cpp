

//!  1 2 3 4 5 6 

#include<iostream>
using namespace std;
int n;
void sp(int n){
    if(n == 0){
        return;
    }
    sp(n-1);
    cout<<n<<" ";
}
int main(){
    n=6;
    sp(n);
}