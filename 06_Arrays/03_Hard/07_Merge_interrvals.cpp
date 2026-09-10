


//! =========================================== Brute Force.... ===========================================  



#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();

        // Step 1: Sort the intervals based on the start time
        sort(intervals.begin(), intervals.end());

        // pehle he sort krke rakh diya haii.. to i ko check krne ki jarurat nhi only check the j..

        vector<vector<int>> ans;

        // Step 2: Iterate through each interval
        for (int i = 0; i < n; i++) {
            int startpnt = intervals[i][0];
            int endpnt = intervals[i][1];

            if (!ans.empty() && endpnt <= ans.back()[1]) { // !ans.empty() means u are not empty something in u matalb pehli iteration ud gyi..i=0 wali
            // ans.back()[1] means the earlier elemnets endpoint before u is less than endpoint of urs.. that means u are not going in...
                
                continue;

            }

            // Check intervals for potential overlaps
            for (int j = i + 1; j < n; j++) {
                // If the next interval starts before or at the current end, it
                // overlaps

                if (intervals[j][0] <= endpnt) {
                    endpnt = max ( endpnt ,  intervals[j][1] ); // Expand the boundary
                }
                
                 else {
                    break; // Stop checking further as the array is sorted to current wala he nhi aa pa rha to sorted kr wajah se to right wale to bade honge wo akisee aayenge...
                }
            }

            // Add the merged interval to the result
            ans.push_back({startpnt, endpnt});
        }

        return ans;
    }
};

/*

This confusing condition
if (!ans.empty() && endpnt <= ans.back()[1])

Let's break it.

ans.empty()

Checks whether ans is empty.

Initially : ans = {}
so:
ans.empty() == true

Therefore:
!ans.empty() :

ans is NOT empty.

Initially:
!true = false

So the condition won't execute.

!What is ans.back()?

!Suppose:

!ans = {{1,6}, {8,12}}

Then:

!ans.back()

!means the last interval:

!{8,12}

And:

!ans.back()[1]

!means its ending point : 12

So:

endpnt <= ans.back()[1] means:
Current interval ka end, already stored last interval ke end se chhota/equal hai.


*/





//! =========================================== Optimal Code..... ===========================================  


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        int n = intervals.size();
        
        sort(intervals.begin() , intervals.end());
        
        vector<vector<int>> ans;

        for(int i=0; i<n; i++){

            if( ans.empty() || intervals[i][0] > ans.back()[1] ){  // intervals[i][0] > ans.back()[1] = measn ki {1,3},{4,6} hai to {1,3} pe pehla wala interval khatam ab new one will start from {4,6}...
                ans.push_back(intervals[i]);
            }
            else { // if not true matlab abhi tk interval chal skta haiii..

                ans.back()[1] = max( ans.back()[1] , intervals[i][1] );
            
            }
        }

        return ans;
    }
};