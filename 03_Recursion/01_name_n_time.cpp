

// Asad Asad Asad Asad Asad

#include<iostream>
using namespace std;
int n;
void sp(int n){
    if(n==0){
        return;
    }
    sp(n-1);
    cout<<"Asad"<<" ";
}

int main(){
    n=5;
    sp(n);
}