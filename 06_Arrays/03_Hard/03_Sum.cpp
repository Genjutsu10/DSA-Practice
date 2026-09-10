


//! =========================================== Brute Force.... ===========================================  



#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        set<vector<int>> res;

        int n = nums.size();

        for ( int i =0 ; i < n ; i++ ){
            for ( int j = i+1 ; j < n ; j++ ){
                for ( int k = j+1 ; k < n ; k++ ){
                    int sum = nums[i] + nums[j] + nums[k];
                    if ( sum == 0 ){

                        vector<int>st = { nums[i] , nums[j] , nums[k] }; 
                        
                        sort( st.begin() , st.end() );
                        
                        res.insert(st);
                    }
                }
            }
        }
        return vector<vector<int>>(res.begin(),res.end());
    }
};



//! =========================================== Slightly Better Force.... ===========================================  



class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        set<vector<int>> res;

        int n = nums.size();

        

        for ( int i =0 ; i < n ; i++ ){

            unordered_set<int> se;           // ye islye ki agar i=0 ke liye hum set mai element dalnege with help of the else wali condition
                                             // so we need to add different element for the i=1 kyuki j ye hamesha i se suru hoga lekin in some case i=0 wala no. is stored in the set..
                                             // that can come in j=1 lekin that's not valid kyuki no duplicate...

            for ( int j = i+1 ; j < n ; j++ ){

                int number = 0 - ( nums[i] + nums[j] );

                if ( se.find( number ) != se.end() ){

                    vector<int> temp = {nums[i], nums[j], number}; 

                    sort(temp.begin(), temp.end());  // 3 numbers ko sort karenge
                    
                    res.insert(temp); // set duplicate triplets ko automatically remove karega
                }
                else{
                    se.insert(nums[j]); // current number ko set me add karo
                }
                
            }
        }

        return vector<vector<int>>(res.begin() , res.end() );
    }
};




//! =========================================== Optimal condition .... =========================================== 




class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        int n = nums.size();

        vector<vector<int>>res;

        sort( nums.begin() , nums.end() );

        for( int i = 0 ; i < n ; i++ ){
            if( i>0 && nums[i] == nums[i-1] ) continue;
            int j = i+1;
            int k = n-1;

            while( j < k ){
                int sum = nums[i]+ nums[j]+ nums[k];

                if( sum > 0){
                    k--;
                }else if( sum < 0 ){
                    j++;
                }else{
                    vector<int>st = { nums[i], nums[j], nums[k] };
                    res.push_back(st);
                    j++;
                    k--;
                    while( j<k && nums[j] == nums[j-1]) j++;
                    while( j<k && nums[k] == nums[k+1]) k--;
                }
            }
        }
        return res;
    }
};


