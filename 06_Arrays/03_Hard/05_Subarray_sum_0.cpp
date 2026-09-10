


//! =========================================== Brute Force.... ===========================================  
// complex one...
// using the count..


#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxLength(vector<int>& arr) {
        
        int n = arr.size();
        int sum;
        int maxi = 0;
        
        for( int i = 0; i < n; i++ ){
            sum = 0 ;
            int count = 0;
            for ( int j = i; j < n; j++ ){
                
                if( sum == 0 ){
                    maxi = max( maxi , count);
                }
                
                sum = sum + arr[j];
                count++;
                
                if( sum == 0 ){
                    maxi = max( maxi , count);
                }
            }
        }
        return maxi;
        
    }
};



//! =========================================== Brute Force.... ===========================================  
// Simpler one...
// using the  i,j...

class Solution {
  public:
    int maxLength(vector<int>& arr) {
        
        int n = arr.size();
        int maxi = 0;
        
        
        for( int i = 0; i < n; i++ ){
            int sum = 0 ;
            
            for ( int j = i; j < n; j++ ){
                
                sum = sum + arr[j];
                
                if( sum == 0 ){
                    maxi = max( maxi , j-i+1);
                }
            }
        }
        return maxi;
        
    }
};




//! =========================================== Optimal Solution.... ===========================================  




class Solution {
  public:
    int maxLength(vector<int>& arr) {
        
        
        int n = arr.size();
        int count = 0;
        int maxi = 0;
        int sum = 0;
        unordered_map<int,int> mp;
        
        
        for( int i = 0; i < n; i++ ){
            sum = sum + arr[i];
            
            if( sum == 0){
                maxi = i+1;
            }
            
            int number = sum ;
            count++;
            
            if( mp.find(number) != mp.end() ){
                maxi = max( maxi ,i-mp[number] );
            }
            else{
                mp[sum]=i;  // yaha pe else mai nhi likhte out of else and run always....
            }               //to koi element like 2,1 pehle append kiya haii badme 2,2 append kr diya..
        }                   // so kya hoga 2,2 bn jayega phir jo max lenght hogi vo km hogi...
        return maxi;        // so questions like the //! Max subarray lenght or evertime always put this is in the else 
    }                       // unless they asked for //! count....
};



// yaha pe else mai nhi likhte out of else and run always....
//to koi element like 2,1 pehle append kiya haii badme 2,2 append kr diya..
// so kya hoga 2,2 bn jayega phir jo max lenght hogi vo km hogi...
// so questions like the //! Max subarray lenght or evertime always put this is in the else 
// unless they asked for //! count....
