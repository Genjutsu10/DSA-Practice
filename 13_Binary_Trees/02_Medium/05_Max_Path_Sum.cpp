
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

    int maxPathSum(TreeNode* root) {

        int maxi = INT_MIN;

        maxPathDown(root, maxi);

        return maxi;
    }

    int maxPathDown(TreeNode* node, int &maxi) {

        if (node == nullptr) {
            return 0;
        }

        // Left subtree se maximum contribution le rahe hai.
        //
        // Agar left side ka sum negative hai,
        // to usko lene ka koi fayda nahi hai.
        // Isliye negative sum ko 0 maan lenge.

        int left = max(0, maxPathDown(node->left, maxi));


        // Same right subtree ke liye.
        //
        // Agar right side ka sum negative hai,
        // to usko ignore kar denge.

        int right = max(0, maxPathDown(node->right, maxi));


        // Current node ke through ek complete path
        // ban sakta hai:
        //
        // left subtree → current node → right subtree
        //
        // Isliye dono side ko add kar sakte hai.

        maxi = max(maxi, left + right + node->val);


        // Parent ke paas jaate time dono sides nahi le sakte.
        //
        // Kyuki parent ke saath ek hi continuous path
        // banana hai.
        //
        // Isliye left aur right me se jo maximum hai
        // usko current node ke saath return karenge.

        return max(left, right) + node->val;
    }
};