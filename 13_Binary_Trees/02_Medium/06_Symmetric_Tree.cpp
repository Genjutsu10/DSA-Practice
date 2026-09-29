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
    void help( TreeNode* dava , TreeNode* ujva , bool& ans ){
        if( dava == nullptr && ujva == nullptr ){
            return;
        }
        if( dava == nullptr || ujva == nullptr ){
            ans = false;
            return;
        }

        if( dava->val != ujva->val ){
            ans = false;
            return;
        }

        if( ans ){
            help(dava->left , ujva->right , ans);
            help(dava->right , ujva->left , ans);
        }
    }

    bool isSymmetric(TreeNode* root) {

        bool ans = true;

        help(root->left , root->right , ans);

        return ans;
                        
    }
};