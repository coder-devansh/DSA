/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
bool remove(TreeNode*root){
    if(root==NULL){
        return false;
    }

  bool left=remove(root->left);
       bool right= remove(root->right);
       if(left==false){
        root->left=NULL;
       }
       if(right==false){
        root->right=NULL;
       }
       if(left || right || root->val==1){
        return true;
       }else{
        return false;
       }
    }

    TreeNode* pruneTree(TreeNode* root) {
        remove(root);
        if(root->val==0 && root->left==NULL && root->right==NULL){
            return NULL;
        }
        return root;

        
    }
};