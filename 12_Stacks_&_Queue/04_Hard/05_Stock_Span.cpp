//! ================================== Brute code ==================================
// Striver Question...


#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector <int> stockSpan(vector<int> arr, int n) {
        vector<int> result;
        for( int i = n-1; i >= 0; i-- ){

            int count = 1;
            int min = arr[i];

            for( int j = i-1; j >= 0 ; j-- ){
                if( min >= arr[j] ){
                    count++;
                }else{
                    break;
                }
            }
            result.push_back( count );
        }

        reverse( result.begin() , result.end() );

        return result;
    }
};


//! ================================== Optimal code ==================================
//? There is more optimal sollution....

class Solution{
    public:

    vector<int> pgee( vector<int>& arr ){

        stack<int> st;
        int n = arr.size();
        vector<int> pge(n);

        for( int i = 0; i < n; i++ ){

            while( !st.empty() && arr[i] >= arr[st.top()] ){
                st.pop();
            }

            if(st.empty()){
                pge[i] = -1;
            }
            else{
                pge[i] = st.top();
            }

            st.push(i);               
        }

        return pge;

    }

    vector <int> stockSpan(vector<int> arr, int n) {

        vector<int> ans(n);
        vector<int> PGE = pgee( arr );

        for( int i = 0; i < n; i++ ){
            ans[i] = abs( PGE[i] - i );
        }

        return ans;
    
    }
};


//! ================================== MORE Optimal code ==================================
// Comments pdh..
// comment wale section mai jaate he question dekh..aue cmp kr...


class Solution {
public:

    vector<int> stockSpan(vector<int> arr, int n) {
        vector<int> ans(n);
        stack<int> st; 

        for (int i = 0; i < n; i++) {

            while ( !st.empty() && arr[st.top()] <= arr[i] ) {
                st.pop();
            }

            if ( st.empty() ) {
                ans[i] = i + 1; // empty hai mtlab koi pge nahi hai mtlab sb ke sab pich wale small haii..so i+1.
            }
            else {
                ans[i] = i - st.top(); // st.top he bada hai baki sb isse chote haii so bich ke elemets is the ans...so i-st.top()
            }

            st.push(i);
        }

        return ans;
    }
};


// Input: n = 7, arr = [120, 100, 60, 80, 90, 110, 115]

// Output: [1, 1, 1, 2, 3, 5, 6]


