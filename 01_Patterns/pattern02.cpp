//   *
//   **
//   ***
//   ****
//   *****

#include<bits/stdc++.h>
using namespace std; 

class Pattern {
public:
    void pattern2(int n) {
        for(int i=0; i<n; i++){
            for(int j=0; j<=i; j++){
                cout << "*";
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
    p.pattern2(n);

  return 0;
}