#include<iostream>
using namespace std;

int main(){
    int n,j,i;
    n=5;
    char a='A';
    

    for(int i=0;i<n;i++){
        char d=a+n-1;
        char q=d-i;
        for(int j=0;j<i+1;j++){
            
            cout<<q;
            q++;
        }
        cout<<endl;
    }



    return 0;
}



//!   E
//!   DE
//!   CDE
//!   BCDE
//!   ABCDE