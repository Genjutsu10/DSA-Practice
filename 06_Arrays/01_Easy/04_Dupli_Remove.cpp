
#include<bits/stdc++.h>
using namespace std;



//! =========================================== Brute Force.... ===========================================

vector<int> removeDuplicates(vector<int> &arr) {
    vector<int> temp;

    for (int i = 0; i < arr.size()-1; i++) {
        if (arr[i] != arr[i+1]) {
            temp.push_back(arr[i]);
        }
    }

    temp.push_back(arr[arr.size()-1]);

    return temp;
}



//! =========================================== OPTIMAL CODE... ===========================================

class Solution {
public:
    vector<int> removeDuplicates(vector<int> &arr) {

        int n = arr.size();
        int i = 0; // i 0th index ko pnt karega... 

        for(int j = 1; j < n; j++) { // j 1th index ko pnt karega..

            if(arr[i] != arr[j]) { // i 0th index pe he rahega unless koi usko diff banda na mil jaye with help of j. jab tk koi naya nhi milta j badhta jayega..
                i++;               // banda milte he i++ hoke us bande ko us i++ location pe leke store kr lega...
                arr[i] = arr[j];
            }
        }

        return vector<int>(arr.begin(), arr.begin() + i + 1); // yaha pe kya hua apne array mai sb elemnts hai magar apnei ki madat se jo start pe 3-4 stored kiye the unique wale unki jarurat haii..
    }                                                         // this is the formula for those all...
};

