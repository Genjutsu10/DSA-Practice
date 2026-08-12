#include<bits/stdc++.h>
using namespace std;
int main(){

    vector<int> arr;
    arr = {5, 7, 3, 8, 1, 2};
    int a, n = arr.size();

    for(int i = 0; i<n; i++){
        int z;
        for(int j = i-1; j >= 0; j--){
            if( arr[j+1] < arr[j]){
                z = arr[j+1];
                arr[j+1] = arr[j];
                arr[j]=z;
            }
        }
    }
    for(int k=0; k<n; k++){
        cout<<arr[k]<<" ";
    }

    return 0;
}


