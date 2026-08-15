#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int missingNum(vector<int>& arr) {
        
        long long n = arr.size();
        
        long long ogsum = ((n+1)*(n+2))/2;
        
        long long sum = 0;
        
        long long number;
        
        for(int i = 0; i<n; i++){
           sum = sum + arr[i]; 
        }
        
        number = ogsum - sum;
        
        return number;
        
        
    }
};