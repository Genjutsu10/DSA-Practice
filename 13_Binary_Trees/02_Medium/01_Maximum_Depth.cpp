//? CHECK THE LAST COD ETHAT IS OPTIMAL ONE CODE OTHER THAN ALL..( STRIVER )...

//! ========================================  LEVEL ORDERED Approach.... =========================================== 
//Using the stack


#include<bits/stdc++.h>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        
        vector<vector<int>> ans;

        if(root == NULL){
            return 0;
        }

        queue<TreeNode*> q;
        q.push(root);
        int count = 0;

        while(!q.empty()){

            int size = q.size();
            vector<int> level;

            for(int i = 0; i < size; i++){

                TreeNode* node = q.front();
                q.pop();

                level.push_back(node->val);

                if(node->left != NULL){
                    q.push(node->left);
                }

                if(node->right != NULL){
                    q.push(node->right);
                }
            }
            count++;

            ans.push_back(level);
        }

        return count;
    }
};


//! ========================================  Recursive Approach.... =========================================== 

// You can do this code using only one count like last one...
//? pehle code padh , comments ko pdh nd then jaake ek question dekh...


class Solution {
public:

    void trav(TreeNode* root , int count1 , int count2, int& maxi ){
        if( root == nullptr ){    
            int sum = count1 + count2 - 1; // 3] parent node se left wala node choose kiya aur phir usme last maai gyee...jb root==null ho gya
            maxi = max( maxi , sum);       // tb humne left mile elements aur right mai mile elements ka count ka sum kiya 
            return;
        }

        trav( root->left , count1+1 , count2 , maxi );  // 1] left mai jitne element mil gye unka count
        trav( root->right , count1 , count2+1 , maxi ); // 2] right mai usi raste mai jitne mil gye unka count 

    }

    int maxDepth(TreeNode* root ) {

        int count1 = 1;  // start ke node ko mojne ke liye count2 =1 bhi lete to koi problme nhi tha..
        int count2 = 0;
        int maxi = 0;
        trav( root , count1 , count2 , maxi);

        return maxi ;

    }
};

//                1
//              /   \
//             2     3
//            / \   / \
//           4   5 6   7
//              /     / \
//             8     9  10

//! same code like the above bur using only one count..


class Solution {
public:

    void trav(TreeNode* root, int count, int& maxi) {

        if(root == nullptr) {
            maxi = max(maxi, count - 1);
            return;
        }

        trav(root->left, count + 1, maxi);
        trav(root->right, count + 1, maxi);
    }

    int maxDepth(TreeNode* root) {

        int count = 1;
        int maxi = 0;

        trav(root, count, maxi);

        return maxi;
    }
};




//! =========================================== OPTIMAL STRIVER CODE.... ===========================================

class Solution {
public:
    int maxDepth(TreeNode* root) {

        if( root == nullptr ){
            return 0;
        }
        
        int lh = maxDepth( root->left );
        int rh = maxDepth( root->right );

        return 1+ max( lh , rh );
    }
};
