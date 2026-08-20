//   1
//   12
//   123
//   1234
//   12345

#include<bits/stdc++.h>
using namespace std; 

class Pattern {
public:
    void pattern3(int n) {
        for(int i=1; i<=n; i++){
            for(int j=1; j<=i; j++){
                cout << j;
            }
            cout << endl;
        }
    }
};


int main(){
    int n;
    cout << "Enter n : ";
    cin >> n;

    Pattern p;
    p.pattern3(n);

  return 0;
}