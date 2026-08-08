

//!  1
//!  01
//!  101
//!  0101
//!  10101
//!  010101
//!  1010101
  
#include<iostream>
using namespace std;
int main(){
    int n,i,d,j;
    n=7;

    for(i=0;i<n;i++){
        for(j=0;j<=i;j++){
            d=i-j;
            if(d%2 == 0){
                cout<<"1";
            }else{
                cout<<"0";
            }

        }
    cout<<endl;
    }
}