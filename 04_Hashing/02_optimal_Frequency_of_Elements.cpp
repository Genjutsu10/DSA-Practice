#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> countFreq(vector<int>& arr) {

    map<int, int> map;
    vector<vector<int>> res;

    int n = arr.size();

    for (int i = 0; i < n; i++) {
        map[arr[i]]++;
    }

    for (auto it : map) {
        res.push_back({it.first, it.second});
    }

    return res;
}

int main() {

    vector<int> arr = {1, 2, 2, 3, 3, 5};

    vector<vector<int>> result = countFreq(arr);

    for (auto it : result) {
        cout << "[" << it[0] << ", " << it[1] << "] ";
    }

    return 0;
}