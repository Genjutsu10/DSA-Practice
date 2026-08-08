#include<iostream>
using namespace std;

int sp(int n){
    if( n == 0 ){
        return 0;
    }
    return n+sp(n-1);

}

int main(){
    int n=10;
    int x=sp(n);
    cout<<x;
}