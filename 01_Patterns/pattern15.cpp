

//!  ABCDE
//!  ABCD
//!  ABC
//!  AB
//!  A

#include<iostream>
using namespace std;

int main(){
    int n;
    n=5;
    for(int i=0;i<n;i++){
        char letter  = 'A';
        for(int j=0;j<n-i;j++){
            cout<<letter;
            letter++;
        }
        cout<<endl;
    }
}

