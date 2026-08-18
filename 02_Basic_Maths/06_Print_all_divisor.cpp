#include<bits/stdc++.h>
using namespace std;

void print_divisors(int n) {
    vector<int> d;
    for(int i=1 ; i*i<=n ; i++){
        if(n%i == 0){
            d.push_back(i);

            if(n/i != i){
                d.push_back(n/i);
            }
        }
    }
        
    sort(d.begin() , d.end());
    for(auto it : d){
        cout<<it<<" ";
    }
}

int main(){
    int n;
    cin >> n;
    print_divisors(n);
}