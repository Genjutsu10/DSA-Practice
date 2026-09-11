


//! =========================================== Brute Force.... ===========================================  



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findTwoElement(vector<int>& arr) {

        int n = arr.size();

        int rep = 0;
        int miss = 0;

        for(int i = 0; i < n; i++) {

            int count = 0;

            for(int j = 0; j < n; j++) {

                if(arr[j] == i + 1)
                    count++;
            }

            if(count == 2)
                rep = i + 1;

            if(count == 0)
                miss = i + 1;
        }

        return {rep, miss};
    }
};



//! =========================================== Better Solution.... ===========================================  




class Solution {
public:
    vector<int> findTwoElement(vector<int>& arr) {

        sort(arr.begin(), arr.end());

        int n = arr.size();

        int ogsum = 1LL * n * (n + 1) / 2;

        int rep;
        int miss;

        int sum = 0;

        for(int i = 0; i < n - 1; i++) {

            sum = sum + arr[i];

            if(arr[i] == arr[i+1]) {
                rep = arr[i];
            }
        }

        sum += arr[n-1];

        miss = ogsum - sum + rep ;

        return {rep, miss};
    }
};



//! =========================================== Better Solution.... ===========================================  



class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {

        vector<int> v;

        unordered_map<int,int> Num_Freq;

        for(int i=0;i<arr.size();i++){
            Num_Freq[arr[i]]+=1;
        }

        for(auto i:Num_Freq){
            if(i.second==2){
                v.push_back(i.first);
                break;
            }
        }

        for(int i=0;i<arr.size();i++){
            if(Num_Freq.find(i+1)==Num_Freq.end()){
                v.push_back(i+1);
                break;
            }
        }

        return v;
    }
};

//! =========================================== OPTIMAL Condition..... ===========================================  
// 2 eqution bano x+y nd x-y....

class Solution {
public:
    vector<int> findTwoElement(vector<int>& arr) {

        long long n = arr.size();

        long long ogsum = n * (n + 1) / 2;

        long long ogsqsum = n * (n + 1) * (2 * n + 1) / 6;

        long long rep;
        long long miss;

        long long sum = 0;
        long long sqsum = 0;

        for(int i = 0; i < n; i++) {

            sum = sum + arr[i];

            sqsum = sqsum + 1LL * arr[i] * arr[i];
        }

        long long result1 = ogsum - sum;      // x-y       miss - rep
        long long result2 = ogsqsum - sqsum;  // x^2-y^2   miss² - rep²

        long long result3 = result2 / result1; // x+y      miss + rep

        miss = (result1 + result3) / 2;
        rep = miss - result1;

        return {(int)rep, (int)miss};
    }
};



