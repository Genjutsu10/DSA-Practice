#include<bits/stdc++.h>
#include <vector>
using namespace std;

int main(){
    vector<int> arr = {5, 7, 3, 8, 1, 2};

    int n = arr.size();

    for(int i=0; i<n; i++){
 
        for(int j=0; j<n-1; j++){

            if( arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }

    for(int k=0; k<n; k++){
        cout<<arr[k]<<" ";
    }
return 0;   
}


// bubble sort for checking goes from left to right check i and i+1...

