// In all the sorting algorithms we can use this sort() function to get ans easily....

//! sort(nums.begin(),nums.end());
//! return nums;


#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {5, 3, 8, 1, 2};

    int n = arr.size();

    for(int i = 0; i < n; i++) {   // this loop for swaping..     
        int min = arr[i];
        int z = i;

        for(int j = i + 1; j < n; j++) {  // this loop for finding min of the array...
            if(arr[j] < min) {
                min = arr[j];
                z = j;  // min no. ka index stored in z
            }
        }

        swap(arr[i], arr[z]); // yaha pe hamesha arr[z] use karenge not min direct because min is independant var not the element of loop..
    }                         // see carefully there is swap so we have to remain our exchange of elements in array...

    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
//


//  array ka min nikalenge aur usko arr[i] ke saath swap karenge...
//  kyu arr[i] kyoki first iteration mai min of array ko 0th index pe store karenge
//  ab 1th indes=x ki baari aayi pr arr[0] mai pehle he min no. store hai..
//  har iteration ke baad loop ke ith index pe i-1 se bada wala no. store hoga
