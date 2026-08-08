

//!  A
//!  BB
//!  CCC
//!  DDDD
//!  EEEEE

#include<iostream>
using namespace std;

int main(){
    int n;
    n=5;
    char letter  = 'A';
    for(int i=0;i<n;i++){
        for(int j=0;j<i+1;j++){
            cout<<letter;
        }
        letter++;
        cout<<endl;
    }
}


