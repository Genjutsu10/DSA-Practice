#include<iostream>
using namespace std;

int main(){
    
    int i,j,a,b,c,d,e,n;
    n=5;
    a=2*n-1;
    b=0;
    c=a-1;
    e=0;
    for(int i=0;i<2*n-1;i++){
        for(int j=0;j<2*n-1;j++){
            // if(i == 0  or j == 0 or i == 2*n-2 or j == 2*n-2){
            //     cout<<n;
            // }else if(i == 1  or j == 1 or i == 2*n-3 or j == 2*n-3){
            //     cout<<n-1;
            // }else if(i == 2  or j == 2 or i == 2*n-4 or j == 2*n-4){
            //     cout<<n-2;
            // }else if(i == 3  or j == 3 or i == 2*n-5 or j == 2*n-5){
            //     cout<<n-3;
        
            b=0;
            c=a-1;
            e=0;
            while(n-e>0){
                if(i == b  or j == b or i == c or j == c){
                    cout<<n-e;
                    b++;
                    c--;
                    e++;
                }
            }
        }cout<<endl;
    }
    
    
    return 0;
}

