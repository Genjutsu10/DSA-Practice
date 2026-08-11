#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {5, 3, 8, 1, 2};

    int n = arr.size();

    for(int i = 0; i < n; i++) {
        int min = arr[i];
        int z = i;

        for(int j = i + 1; j < n; j++) {
            if(arr[j] < min) {
                min = arr[j];
                z = j;
            }
        }

        swap(arr[i], arr[z]);
    }

    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}