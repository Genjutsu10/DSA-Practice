#include <bits/stdc++.h>
using namespace std;

void reverse( int arr[] , int n ){
    int i=0,p=0,c,temp;
    
    for(int i=0;i<n/2;i++){
        temp=arr[i];
        arr[i]=arr[n-1-i];
        arr[n-i-1]=temp;
    }
    
    
}
int main(){
    int n=6;
    
    int arr[n]={1,2,3,4,5,6}; 

    reverse(arr,n); 

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
   
}