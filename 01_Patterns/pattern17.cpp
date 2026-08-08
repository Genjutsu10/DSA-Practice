

//!       A
//!      ABA
//!     ABCBA
//!    ABCDCBA
//!   ABCDEDCBA

#include<iostream>
using namespace std;

int main(){
    char d='A';
    char a=d-1;
    int n;
    n=5;
    char letter  = 'A';
    for(int i=0;i<n;i++){
        char letter  = 'A';
        for(int j=0;j<n-i-1;j++){
            cout<<" ";
        }
        for(int j=0;j<i+1;j++){
            cout<<letter;
            letter++;
        }
        for(int j=0;j<i;j++){
            cout<<a;
            a--;
        }
        a=a+i+1;
        
    cout<<endl;
    }

    return 0;
}


//!       A
//!      ABA
//!     ABCBA
//!    ABCDCBA
//!   ABCDEDCBA