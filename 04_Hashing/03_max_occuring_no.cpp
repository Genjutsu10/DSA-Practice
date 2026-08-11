#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {1, 2, 2, 3, 3, 3, 4};

    map<int, int> freq;

    for (int i = 0; i < arr.size(); i++) {
        freq[arr[i]]++;
    }

    int maxFreq = 0;
    int value = arr[0];

    for (auto it : freq) {
        if (it.second > maxFreq) {
            maxFreq = it.second;
            value = it.first;
        }
    }

    cout << "Most times seen element: " << value << endl;
    cout << "Frequency: " << maxFreq << endl;

    return 0;
}