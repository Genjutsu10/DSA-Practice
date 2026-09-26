#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
     TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
};

class Solution{
	public:

        void transverse(TreeNode* root, vector<int>& result1 ,vector<int>& result2 ,vector<int>& result3 ) {

            if (root == nullptr) {
                return;
            }

            result2.push_back(root->data);

            transverse( root->left, result1 , result2, result3 );

            result1.push_back(root->data);

            transverse( root->right, result1 , result2, result3 );

            result3.push_back(root->data);
        }

		vector<vector<int>> treeTraversal(TreeNode* root){

		    vector<int> result1 , result2, result3;

            transverse( root, result1 , result2, result3 );

            return { result1 , result2, result3 };
		}
};