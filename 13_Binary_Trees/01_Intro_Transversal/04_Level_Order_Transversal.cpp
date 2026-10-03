#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
     TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
};
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {

        queue<TreeNode*>q;
    
        vector<vector<int>> ans;

        if(root == NULL){
            return ans;
        }

        q.push( root ); // q pehlw khali tha to usme root dal diya first node 

        while( !q.empty() ){

            int n = q.size();  // pehle iterration mai sirf root hai mtlab n=1 magar agli bar uske 2 child honge so hme for loop dono child ke lie chalan pdega..

                               //! to hum kya krenge pehel node ko level mai dalenge , pop krenge , useke left aur right ko queue mai dalenge fir ye hua us ek ke lie uska bhi ek brother hoga in the queue jb humne size of queue moja tha ( n )..
                               //! to ab same wee have to do with the second one also...
            vector<int> level;

            for( int i = 0; i < n; i++ ){

                TreeNode* node = q.front(); // q ka jo pehla element tha usko dal diya node mai 
                q.pop();                    // fir us q.front ko pop kiya..

                level.push_back( node->data );  // usi wale queue ke front ke val ko level mai push kiya

                if( node->left != nullptr ){ // fir que khali na ho jaye iske liye usme node ka left aur right dal diya..
                    q.push( node->left );
                }
                if( node->right != nullptr ){ // same agar right hai to wo dal diya..
                    q.push( node->right );
                }
            }
            ans.push_back(level);
        }

        return ans;

    }
};