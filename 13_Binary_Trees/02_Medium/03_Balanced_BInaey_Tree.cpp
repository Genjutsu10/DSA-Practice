
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        
        return help( root ) != -1;

    }

    int help( TreeNode* root ){
        if( root == nullptr ){
            return 0;
        }

        int lh = help( root->left );
        int rh = help( root->right );

        if( lh == -1 ){
            return -1;
        }
        if( rh == -1 ){
            return -1;
        }


        if( abs( lh - rh ) > 1 ){
            return -1;
        }

        return 1 + max( lh,rh );

    }
};



