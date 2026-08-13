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

//! bubble sort har ek iteratiion ke baad ya phir  i th iteraton ke baad  (n-1)-i th index pe element set ho jata hai..
//! matlab agar i=0 hai , to (n-1)th index pr max element store hoo jayega...

// take 9,8,5,4,2,10,2,7,11,2
// isme phle 9 hoga 2 tk pr 10 pe nhi hoga lekin aur loop ruk nhi jayegi. hum cmp j+1 ko kr rhe hai to ab j pr 10 store hoga aur aaghe check krega...

