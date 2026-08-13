#include<bits/stdc++.h>
using namespace std;

void insertion_sort(int arr[], int curr, int n){
    if(curr == n) return;
    
    int prev = curr;
    while(prev > 0 && arr[prev-1] > arr[prev]){
        swap(arr[prev-1], arr[prev]);
        prev--;
    }
    
    insertion_sort(arr, curr+1, n);
}

int main(){
    int arr[] = {13, 46, 24, 52, 20, 9};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    cout << "Before: ";
    for(int i=0; i<n; i++) cout << arr[i] << " ";
    cout << endl;
    
    insertion_sort(arr, 0, n);
    
    cout << "After: ";
    for(int i=0; i<n; i++) cout << arr[i] << " ";
    cout << endl;
    
    return 0;
}