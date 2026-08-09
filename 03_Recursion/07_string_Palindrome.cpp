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

// class Solution {
// public:
//     bool isPalindrome(string s) {
//         char temp ;
//         int  i=0;
//         int n = s.size();
//         string clean = "";

//         while( i < n ){
//             if( isalnum(s[i]) ){
//                 clean = clean + char(tolower(s[i]));
//             }
//             i++;
//         }
//         i=0;
//         string samp = clean;
//         int a = clean.size();

//         while(i<a/2){
//             temp = clean[i];
//             clean[i] = clean[a-i-1];
//             clean[a-i-1] = temp;
//             i++;
//         }
//         if(samp == clean){
//             cout<<clean<<" is palindrome";
//         }else{
//             cout<<clean<<" is not palindrome";
//         }

//     return samp == clean;  
//     }
// };