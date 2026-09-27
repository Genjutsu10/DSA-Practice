//! ========================================  Brute Force.... =========================================== 


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        int n = nums.size();
        vector<int>res;

        if( n == 1){
            return nums;
        }

        for( int i = 0; i <= n-k; i++ ){

            int maxi = nums[i];

            for( int j = i; j < k+i; j++ ){
                if( nums[j] > maxi ){
                    maxi = nums[j];
                }
            }
            res.push_back(maxi);
        }
        return res;
        
    }
};

//! ========================================  Optimal Force.... =========================================== 
// last wala explaination check kroo...
// fir uske upar ka diagram...

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        deque<int>dq;
        vector<int>result;
        int n = nums.size();

        for( int i = 0; i < n; i++ ){


            //for keepping the dequeue size of k
            if( !dq.empty() && dq.front() <= i-k ){ 
                dq.pop_front(); 
            }

            // Remove smaller elements from the back
            while( !dq.empty() && nums[dq.back()] <= nums[i] ){
                dq.pop_back();
            }

            // Add current index which is cmparing all the time..
            // or the element whwn the dq is empty..
            dq.push_back(i);

            // Window is complete..
            // starting mai atleast k elements should be in the queue
            // k elements banate he push kr do usko..
            // ye sirf use kiya for the start mai stack mai 1 element aate he push na krde isliye...
            if( i >= k-1 ){
                result.push_back( nums[dq.front()] );
            }

        }
        return result;
        
    }
};
/*

                 DEQUE
                  ↓
              FRONT / FIRST
                  ↓
              +-------+
              |   10  |  ← LARGEST
              +-------+
              |   7   |
              +-------+
              |   5   |
              +-------+
              |   2   |  ← SMALLEST
              +-------+
                  ↑
              BACK / LAST


        Deque is maintained in
        DECREASING ORDER

        10  →  7  →  5  →  2
       HIGH                LOW


*/  

/*


        SLIDING WINDOW MAXIMUM
        -----------------------

        What we have to do:

        1. Window ko maintain karo
           → har time window ka size = k hona chahiye.


        2. Deque me INDEX store karo
           → values nahi.

           dq.push_back(i);


        3. Window ke bahar ka element hatao

           Agar:

           dq.front() <= i-k

           iska matlab ye index current
           window ke bahar chala gaya.

           → pop_front()


        4. Deque ko DECREASING ORDER me maintain karo

           New element = nums[i]

           BACK se check karo:

           agar:

           nums[dq.back()] <= nums[i]

           → pop_back()

           Aisa tab tak karo jab tak
           back wala element bada na mil jaye.


        5. Current index ko deque me daalo

           dq.push_back(i);


        6. Jab first complete window ban jaye

           i >= k-1

           tab:

           nums[dq.front()]

           ko answer me push karo.
      
*/