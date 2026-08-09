#include <bits/stdc++.h>
using namespace std;
int main(){
    string str= "abmnba";
    string samp=str;
    int c,i=0,n=str.size();
    
    while(i<n/2){
    
        c=str[i];
        str[i]=str[n-1-i];
        str[n-i-1]=c;
        i++;
    }
    if( str == samp){
        cout<<"Palindrome"<<endl;;
        for(int i=0;i<n;i++){
            cout<<str[i];
        }
        
    }else{
        cout<<"Not Palindrome";
    }

    return 0;
}

