
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

    int help( TreeNode* root , int& maxi ){
        if( root == nullptr ){
            return 0;
        }
        
        int lh = help( root->left , maxi );

        int rh = help( root->right , maxi );

        maxi = max( maxi , lh+rh );

        return 1+max(lh,rh);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {

        int maxi = 0;

        help( root , maxi  );

    	return maxi;
    }
};
/*
Agar kisi node ke pass left aur right dono side
naye nodes/subtrees ban rahe hai,
to us node par left ki height aur right ki height
ko add karke diameter check karna zaruri hai.

jo ki hai after checking root->left & root->right ...

Kyuki us node ke through ek path ban sakta hai:
left subtree → current node → right subtree

Isliye:
diameter = lh + rh

Lekin height ke liye dono ko add nahi karenge, jo ki max hoga..
kyuki upar jaate time sirf ek side continue kar sakte hai.

Isliye height:
1 + max(lh, rh)

*/


/*
        1
       / \
      2   3
         / \
        4   6
           /
          7
           \
            8

At every node:

lh = left subtree ki height
rh = right subtree ki height

Jaha kisi node ke left aur right dono taraf
subtree/node ban rahe hai, waha:

diameter = lh + rh

Kyuki path aise ban sakta hai:

left subtree → current node → right subtree


Example:

Node 8:
lh = 0
rh = 0
height = 1

Node 7:
lh = 0
rh = 1
height = 2

Node 6:
lh = 0
rh = 2
height = 3

Node 4:
lh = 0
rh = 0
height = 1

Node 3:
lh = 1
rh = 3

diameter = 1 + 3
         = 4

height = 1 + max(1,3)
       = 4


Node 2:
lh = 0
rh = 0
height = 1

Node 1:
lh = 1
rh = 4

diameter = 1 + 4
         = 5

maxi = 5


IMPORTANT:

Height ke liye:
1 + max(lh, rh)

Diameter ke liye:
lh + rh

Time Complexity = O(N)
Space Complexity = O(N) in worst case
*/