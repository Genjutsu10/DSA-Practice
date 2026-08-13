#include <bits/stdc++.h>
#include <vector>
using namespace std;

void sortmerge(vector<int> &arr, int low, int mid, int high){
    
    vector<int> news;

    int left=low;     // starting index of left half of arr
    int right=mid+1;  // starting index of right half of arr


    // Storing elements in temporary array in sorted order

    while( left <= mid && right <= high ){
        if( arr[left]<=arr[right] ){
            news.push_back( arr[left] );
            left++;
        }else{
            news.push_back( arr[right] );
            right++;
        }
    }

    // If elements are still left on the left half....
    while( left <= mid){
        news.push_back( arr[left]);
        left++;
    }

    // If elements are still left on the right half....
    while( right <= high ){
        news.push_back( arr[right] );
        right++;
    }

    // If elements are still left on the left half.....
    for (int i = low; i <= high; i++) {
        arr[i] = news[i - low];
    }


    int s = news.size();

}


void ms( vector<int> &arr , int low , int high ){

    if ( low >= high ){
            return ;
    }
    int mid = (low + high)/2;
    ms(arr , low , mid );      //1) CODE for left side of arrays and it goes call it again and again until every array becomes the single array..... 
    ms(arr , mid+1 , high );   //2)  CODE for right side of arrays and it goes call it again and again until every array becomes the single array.....

    sortmerge(arr,low,mid,high); // CODE for sorting the 1) and 2) and after that sorting and merging 1 & 2.... 
}

int main() {
    vector<int> arr = {3, 1, 2, 4, 1, 5, 2, 6, 4};
    int n = arr.size();

    ms(arr, 0, n - 1);


    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

// void merge(vector<int> &arr, int low, int mid, int high) {
//     vector<int> temp; // temporary array
//     int left = low;      // starting index of left half of arr
//     int right = mid + 1; // starting index of right half of arr

//     // Storing elements in temporary array in sorted order
//     while (left <= mid && right <= high) {
//         if (arr[left] <= arr[right]) {
//             temp.push_back(arr[left]);
//             left++;
//         } else {
//             temp.push_back(arr[right]);
//             right++;
//         }
//     }

//     // If elements are still left on the left half
//     while (left <= mid) {
//         temp.push_back(arr[left]);
//         left++;
//     }

//     // If elements are still left on the right half
//     while (right <= high) {
//         temp.push_back(arr[right]);
//         right++;
//     }

//     // Transferring all elements from temp back to arr
//     for (int i = low; i <= high; i++) {
//         arr[i] = temp[i - low];
//     }
// }

// void mergeSort(vector<int> &arr, int low, int high) {
//     if (low >= high) return; // Base case: single element

//     int mid = low + (high - low) / 2;

//     mergeSort(arr, low, mid);      // Left half recursion
//     mergeSort(arr, mid + 1, high);  // Right half recursion
//     merge(arr, low, mid, high);     // Merging two halves
// }

// int main() {
//     vector<int> arr = {3, 1, 2, 4, 1, 5, 2, 6, 4};
//     int n = arr.size();

//     mergeSort(arr, 0, n - 1);

//     for (int i = 0; i < n; i++) {
//         cout << arr[i] << " ";
//     }
//     cout << endl;

//     return 0;
// }
