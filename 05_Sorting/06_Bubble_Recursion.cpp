#include<bits/stdc++.h>
using namespace std;

void bubble(int arr[],int n){
    if(n == 1){  // this condtion is for after every i iteration last elemnt of array is settled down 
        return ; // that is why in fun call using the n-1; when n==1 only one elemnt is remaind in the arr. no need of update..
    }
    int c = 0;

    for(int j = 0; j<n-1; j++){
        if( arr[j] > arr[j+1] ) {
            swap( arr[j] , arr[j+1] );
            c++; // c is for when there is no swap in whole iteration at that time the whole array is sorted..
        }        // and if u think about the elmts back of that iteration no. that all are already sorted....
    }
    if( c == 0){
        return;
    }
    bubble(arr,n-1);
}

int main(){
    int arr[]={2,5,9,6,7,6,1};
    int n = sizeof(arr)/sizeof(arr[0]);

    bubble(arr,n);

    cout<<"After sorting :";

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}