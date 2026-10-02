//?   TASK 4


#include<iostream>
using namespace std;

int a = 10;

int main(){
    int b = 20;
    cout<<"Global Variable:"<<a<<endl;
    cout<<"Local Variable:"<<a<<endl;
    {
        int c = 30;
        cout<<"block variable:"<<c<<endl;
    }
}

// //! Static

// class Fruit{
//     public:
//         void show(){
//             cout<<"This is a fruit"<<endl;
//         }
//         void show( string name ){
//             cout<<"Fruit name :"<<name;
//         }
// };

// int main (){
//     Fruit f;

//     f.show();
//     f.show("Apple");

//     return 0;
// }

//! Dynamic 

// class Fruit{        // base
//     public:
//         virtual void taste(){
//             cout<<" fruit has taste "<<endl;
//         }
// };

// class Mango : public Fruit{        // derived
//     public : void taste(){
//         cout<<"Mango is Sweet"<<endl;
//     }
// };

// int main (){
//     Fruit *ptr;

//     Mango m;   // object
//     ptr = &m;
//     ptr -> taste();

//     return 0;
// }



//! Implicit type 


// int main(){
//     int a = 10;
//     int b = 2.5;
//     float result = a+b;
//     cout<<result<<endl;
//     return 0;
// }


//! Explicit type 


// int main(){
//     float x = 10;
//     int y = (int) x;

//     cout<<y<<endl; 
//     return 0;
// }

//! Strong type python code...

// age = 20
// name = "Asad"
// print( age + name ) #error

//! Weak type JS code...

// let x = 20;
// let y = "asad";
// console.log(x+y);





































//?   TASK 5


//! Logical AND

#include<bits/stdc++.h> 
using namespace std;

int main(){
    int a = 10;
    int b = 20;

    if(a > 5 && b > 15) cout << "Both Conditions are true";

    return 0;
}

// //! Logical OR

#include<bits/stdc++.h> 
using namespace std;

int main(){
    int a = 10;
    int b = 20;

    if(a > 5 || b > 15) cout << "At least one condition is true";

    return 0;
}


//! Logical AND

#include <bits/stdc++.h> 
using namespace std;

int calls = 0;

bool first(){
    cout << "First Function called"<< endl;
        calls++;
    return false;
}

bool second(){
    cout << "Second Function called"<< endl;
       calls++;
    return true;
}

int main(){
    if(first() && second()) cout << "True";
    cout << "Function calls = " << calls;

    return 0;
}




//! Logical OR 

#include <bits/stdc++.h> 
using namespace std;

int calls = 0;

bool first(){
    cout << "First Function called"<< endl;
    calls++;
    return true;
}

bool second(){
    cout << "Second Function called"<< endl;
    calls++;
    return false;
}

int main(){
    if(first() || second()) cout << "True";
    cout << "Function calls = " << calls;

    return 0;
}
















