
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
                
            }else{
                i++;
            }
        }
        return asteroids;
    }
};




//! =========================================== OPTIMAL CODE... ===========================================


