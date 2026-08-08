
//! 10 9 8 7 6 5 4 3 2 1

#include<iostream>
using namespace std;

void sp(int n){
    if( n == 0 ){
        return;
    }
    cout<<n<<" ";
    sp(n-1);

}

int main(){
    int n=10;
    sp(n);
}