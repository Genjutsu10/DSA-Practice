#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> countFreq(vector<int>& arr) {
    int n = arr.size();
    int count = 1;

    sort(arr.begin(), arr.end());

    vector<vector<int>> ass;

    for (int i = 0; i < n; i++) {
        if (i + 1 < n && arr[i] == arr[i + 1]) {
            count++;
        } else {
            ass.push_back({arr[i], count});
            count = 1;
        }
    }

    return ass;
}

int main() {
    vector<int> arr = {1, 2, 2, 3, 3, 5};

    vector<vector<int>> result = countFreq(arr);

    cout << "[";

    for (int i = 0; i < result.size(); i++) {
        cout << "[" << result[i][0] << "," << result[i][1] << "]";

        if (i != result.size() - 1)
            cout << ",";
    }

    cout << "]";

    return 0;
}