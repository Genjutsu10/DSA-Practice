#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Partition function to place pivot at its correct position
int partition(vector<int> &arr, int low, int high) {
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j) {
        // Move i right until an element strictly greater than pivot is found
        while (arr[i] <= pivot && i <= high - 1) {
            i++;
        }

        // Move j left until an element less than or equal to pivot is found
        while (arr[j] > pivot && j >= low + 1) {
            j--;
        }

        // Swap elements at i and j if they haven't crossed
        if (i < j) {
            swap(arr[i], arr[j]);
        }
    }

    // Place pivot in its correct sorted position by swapping with arr[j]
    swap(arr[low], arr[j]);
    
    return j; // Return partition index
}

// Main recursive Quick Sort function
void qs(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pIndex = partition(arr, low, high);

        // Recursively sort left and right subarrays
        qs(arr, low, pIndex - 1);
        qs(arr, pIndex + 1, high);
    }
}

// Wrapper function usesd for recursive use....
vector<int> quickSort(vector<int> arr) {
    qs(arr, 0, arr.size() - 1);
    return arr;
}

int main() {
    vector<int> arr = {4, 6, 2, 5, 7, 9, 1, 3};
    int n = arr.size();

    cout << "Before sorting: ";
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;

    arr = quickSort(arr);

    cout << "After sorting:  ";
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
