


//! =========================================== Brute Force.... ===========================================  
/*

Inversion count: the array does not necessarily have to contain only positive numbers. The condition is simply arr[i] > arr[j], so negatives are fine too.
Reverse Pairs: the condition is arr[i] > 2 * arr[j], and because arr[j] can be negative, arr[i] > arr[j] does not guarantee arr[i] > 2 * arr[j].

Example:

left = -5
right = -3

left > right?
-5 > -3  ❌


*/

#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    int inversionCount(vector<int> &arr) {
        
        int n = arr.size();
        int count = 0;
        
        for( int i = 0; i < n; i++ ){
            for ( int j = i ; j < n; j++ ){
                
                if( i<j && arr[i] > arr[j] ){
                    count ++;
                }
            }
        }
        return count;
        
        
    }
};



//! =========================================== Optimal Solution..... ===========================================  


int countt = 0 ;

void merge( vector<int> &arr, int low, int mid, int high ){

    vector<int> news;

    int right = mid+1;;
    int left = low;

    while( left <= mid && right <= high ){

        if( arr[left] <= arr[right] ){
            news.push_back(arr[left]);
            left++;
        }
        else{
            news.push_back(arr[right]);
            countt = countt + mid-left+1;
            right++;
        }
    }

    while( left <= mid ){
        news.push_back(arr[left]);
        left++;
    }

    while( right <= high ){
        news.push_back(arr[right]);
        right++;
    }

    for( int i = low ; i <= high; i++ ){
        arr[i] = news[i-low];
    }

}


void ms( vector<int> &arr , int low , int high ){

    int mid = (low + high)/2;

    if( low >= high ){
        return;
    }

    ms( arr , low , mid );
    ms( arr , mid+1 , high );

    merge( arr , low , mid , high );

}


/*

agar 1st and 2nd array is sorted then..
agar pehel ka i'th element dusre kr j'th element se bada hai that means ki i se mid tk ke sab elemnt is grater than j...
and thats our count 




*/

