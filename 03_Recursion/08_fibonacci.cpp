class Solution {
public:
    int fib(int n) {
        int sum, i, c;
        int a=0,b=1;
        sum=0; 
        for(i=0;i<n;i++){
            c=a+b;
            a=b;
            b=c;
        }
        return a;  
    }
};