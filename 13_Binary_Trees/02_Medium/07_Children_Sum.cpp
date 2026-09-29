class TreeNode {
       int val;
       TreeNode *left, *right;
       TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#include<bits/stdc++.h>
using namespace std;
 
class Solution {
public:

    int help( TreeNode* root ){

        if( root == nullptr ){
            return 0;
        }

        if(root->left == nullptr && root->right == nullptr) {
            return root->val;
        }

        int lh = help( root->left );
        int rh = help( root->right );

        if( lh == INT_MIN ) return INT_MIN;
        if( rh == INT_MIN ) return INT_MIN;

        if( root->val != lh+rh ){
            return INT_MIN;
        }

        return root->val;    
        
    }

    bool checkChildrenSum(TreeNode* root) {

       return help( root )!= INT_MIN;
       
    }
};
