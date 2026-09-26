struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//! =========================================== LITTLE BIT OPTIMAL CODE... ===========================================


#include<bits/stdc++.h>
using namespace std;
 
class Solution {
public:

    void help( TreeNode* p, TreeNode* q , bool& u ){

        if( p == nullptr || q == nullptr ){

            if( p != q ){
                u = false;
            }
            return;
        }

        if( p->val != q-> val ){ //  ( u != false && ( p->val != q-> val )) no need of using this cause if u once make it false there is no way that it gonna make true again..
            u = false;
        }

        help( p->left , q->left , u );
        help( p->right , q->right , u );

    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool u = true;
        help( p , q , u );
        return u;
    }
};

//! =========================================== OPTIMAL CODE... ===========================================

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {

        if( p == nullptr && q == nullptr ){
            return true;
        }

        if(p == nullptr || q == nullptr){
            return false;
        }

        if( p->val != q->val ){
            return false;
        }
        
        return (isSameTree( p->left , q->left ) && isSameTree( p->right , q->right ) );

    }
};
