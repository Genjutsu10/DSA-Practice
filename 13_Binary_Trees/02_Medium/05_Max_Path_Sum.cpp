
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

//! pehle isse dekho....

class Solution {
public:
    int help( TreeNode* root , int& maxi ){

        if( root == nullptr ){
            return 0;
        }

        int lh =  help(root->left , maxi) ; // niche tk jayega..lat mai null mila to 0.( 5 tk gya o return right mai kush nhi to 2 ka lh = 5 ){ root->val + max( lh , rh ); lh=0 && rh=0 so return only node->data...}
        int rh =  help(root->right , maxi) ; // right mai check krega nhi to zero..( 5 se 2 pe aaya right ko gya at 3 mai gya  3 ke left mai no rigth mai no si 2 ka rh = 3)

        maxi = max ( maxi , root->val+lh+rh ); // hume yaha pe mil ahi ek tree look like ^ lh there rh there so add node so we get sum..
        // firse return mar diya at 2 ab for sum of path ke liye ( rh + lh + node->val ) 
        // 

        return root->val + max( lh , rh ); // but at the next node like 1 so like 1 ke upar koi hota tb usko dena khudki value ( node->data ).... + koi largest sum wala node like=[2,5] or [2,3] jiska jyada uski ko return krega...


//         1
//      /    \
//     2      3
//    /  \   / \
//   5    3 4   6
//              /
//             7
//              \
//               8

    }

    int maxPathSum(TreeNode* root) {
        
        int maxi = INT_MIN;
        help( root , maxi );
        return maxi;

    }
};





// fir isse...
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