#include<bits/stdc++.h>
using namespace std;

int main(){
    int i, a, n = 4;
    int count = 0;
    for(int i=2;i*i<=n;i++){
        if( n%i == 0){
            count++;
            break;
        }
    }
    if( n==1 ){
        cout<<"Not Prime number";
    }else if( count > 0 ){
        cout<<"Not Prime number...";
    }else{
        cout<<"Prime Number...";
    }
    return 0;
}