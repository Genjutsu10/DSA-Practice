
//!   4444444
//!   4333334
//!   4322234
//!   4321234
//!   4322234
//!   4333334
//!   4444444

#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int i,j,n,a,top,left,right,down,value;
    n=4;
 
    
    for(int i=0;i<2*n-1;i++){
        for(int j=0;j<2*n-1;j++){
            top=i;
            left=j;
            down=2*n-2-i;
            right=2*n-2-j;
            a = min({top,left,right,down});
            
            value=n-a;
            cout<<value;

        }cout<<endl;
    }
    
    
    return 0;
}

