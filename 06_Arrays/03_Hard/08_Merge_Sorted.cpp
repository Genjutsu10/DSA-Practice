


//! =========================================== OPTIMAL Condition..... ===========================================  



#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int i = m-1;
        int j = n-1;
        int k = 1;

        while( i>=0 && j>=0 ){
            if ( nums1[i] > nums2[j] ){
                nums1[m+n-k] = nums1[i];
                i--;
                k++;
            }else if( nums1[i] < nums2[j] ){
                nums1[m+n-k] = nums2[j];
                j--;
                k++;
            }else{
                nums1[m+n-k] = nums1[i];
                k++;
                i--;
            }
        }
        while( j >= 0 ){
            nums1[m+n-k] = nums2[j];
            k++;
            j--;
        }
        //here u might think that the why the same WHILE loop for the i didnt come...
        //! its simple.. u are modifiying the nums1 so even if j becomes -1 at that time nums1 get automatically sorted..
        //ex. nums1 = [1,2,3,0,0,0]...
    }
};

/*


nums2 = [4,5,6]

Initially:

i = 2  → 3
j = 2  → 6
k = 1  → position 5

We compare from the back:

3 < 6 → put 6
3 < 5 → put 5
3 < 4 → put 4

Now:

nums1 = [1,2,3,4,5,6]

And:

i = 2
j = -1

Your main loop:

while(i >= 0 && j >= 0)

stops because j >= 0 is false.


*/



        
