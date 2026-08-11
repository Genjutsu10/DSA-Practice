#include<bits/stdc++.h>
using namespace std;
int main(){

    vector<int> arr;
    arr = {1,5,6,8,9,8,9,5,6,4,5};
    int n = arr.size();

    for(int i = 0; i<n; i++){
        for(int j = n-1; j>0; j--){
            if( arr[j-1] > arr[j]){
                swap(arr[j],arr[j-1]);
            }
        }
    }
    for(int k=0; k<n; k++){
        cout<<arr[k]<<" ";
    }

    return 0;
}


// just like bubble sort only that the bubble sort goes from left to right i and i+1
// and insert sort goes from last to first check i and i-1