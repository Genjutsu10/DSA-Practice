#include<bits/stdc++.h>
using namespace std;

int main(){
    int i, a, n = 36;
    for(int i=1;i*i<=n;i++){
        if( n%i == 0){
            cout<<i<<" ";
            a=n/i;
            cout<<a<<" ";
        }
    
    }
    return 0;
}