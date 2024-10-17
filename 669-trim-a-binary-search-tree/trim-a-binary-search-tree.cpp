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

TreeNode*construct(TreeNode*root,int low,int high,TreeNode*prev){
    if(root==NULL){
        return NULL;
    }
    
  
    root->left=construct(root->left,low,high,prev);
    
    root->right=construct(root->right,low,high,prev);
     if (root->val < low || root->val > high) {
       
        return (root->left != NULL) ? root->left : root->right;
    }
    return root;
}
 TreeNode* trimBST(TreeNode* root, int low, int high) {
   TreeNode*prev=NULL;
        return construct(root,low,high,prev);
        
    }
};