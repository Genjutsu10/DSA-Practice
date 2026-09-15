#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    void generate(string s , vector<string> &result , int left , int right){
        
        if(left == 0 && right == 0){
            result.push_back(s);
            return;
        }

        if(left > 0){
            s.push_back('(');
            left--;

            generate(s , result , left , right);

            s.pop_back();
            left++;
        }

        if(right > left){
            s.push_back(')');
            right--;
            
            generate(s , result , left , right);
        
            s.pop_back();
            right++;
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string s;
        int left = n;
        int right = n;

        generate(s , result , left , right);
        
        return result;
    }
};