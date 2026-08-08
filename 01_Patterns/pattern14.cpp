#include <iostream>
using namespace std;

int main(){
    int n;
    n=5;
    for(int i=0;i<n;i++){
        char letter  = 'A';
        for(int j=0;j<i+1;j++){
            cout<<letter;
            letter++;
        }
        cout<<endl;
    }
}

//! A
//! AB
//! ABC
//! ABCD
//! ABCDE
