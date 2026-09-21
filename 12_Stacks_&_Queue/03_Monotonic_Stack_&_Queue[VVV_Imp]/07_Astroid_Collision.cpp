
//! ========================================  Brute Force.... =========================================== 

/*

first i = 0 pe i+1 ke saath checck krenge agar change hoga to koi ek ud jayega so we need to check again the i=0 and i+1
ex.2,-2,-3 hai 

1st step : 5,3,-1,-2       i=1
2nd step : 7,3,-2          i=2 ho jata agar i++ krte  lekin here we need to check the i=0 and i=1 againnnnnn... so therfore i--..


*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        int n = asteroids.size();
        int i = 0;

        while( i < n-1 ){
            
            if( asteroids[i] > 0 && asteroids[i+1] < 0 ){
                int sum = asteroids[i] + asteroids[i+1];

                if( sum > 0 ){
                    asteroids.erase( asteroids.begin() + i+1 );
                }

                if( sum < 0 ){
                    asteroids.erase( asteroids.begin() + i );
                }

                if( sum == 0 ){
                    asteroids.erase( asteroids.begin() + i , asteroids.begin() + i + 2 );
                }

                n = asteroids.size();

                if( i > 0 ){     
                    i--;    
                }
                // [10, 2, -5]
                // i = 1

                // 10  2  -5
                //     ↑   ↑

                // After erasing 2:

                // [10, -5]

                // We are still at:
                // i = 1
                // But we need to check the new pair starting at index 0:

                // 10  -5
                // ↑    ↑
                // 0    1....



            }else{
                i++;
            }
        }
        return asteroids;
    }
};




//! =========================================== OPTIMAL CODE... ===========================================



class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

        int n = asteroids.size();
        stack<int> st;

        for(int i = 0; i < n; i++) {

            bool alive = true; // used to deciding that , the while loop should run or not

            while(alive && !st.empty() && st.top() > 0 && asteroids[i] < 0) {

                int sum = st.top() + asteroids[i];

                if(sum < 0) {   // its okk..
                    st.pop();
                }
                else if(sum == 0) {   // i am using the  pop() & i++ in above example when sum == 0 but thats the key  they are using the bool operator to decide...
                    st.pop();
                    alive = false;
                }
                else {
                    alive = false;  // so it is used when u want to skip the iteration means ki going from i=0 to i=1 nd likwise...
                }
            }

            if(alive) {
                st.push(asteroids[i]);
            }
        }

        vector<int> ans(st.size());

        for(int i = ans.size() - 1; i >= 0; i--) {
            ans[i] = st.top();
            st.pop();
        }
        
        return ans;
    }
};

