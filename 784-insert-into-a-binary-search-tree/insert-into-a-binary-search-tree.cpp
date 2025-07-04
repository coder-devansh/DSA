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
TreeNode*fixVal(TreeNode*root,int val){
    if(root==NULL){
        return new TreeNode(val);
    }
   if(root->val>val){
    root->left=fixVal(root->left,val);
   }else{
    root->right=fixVal(root->right,val);
   }
   return root;
}
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode*dummy=root;
       return fixVal(root,val);
        
    }
};