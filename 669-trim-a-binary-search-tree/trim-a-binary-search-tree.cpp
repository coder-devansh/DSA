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
vector<int>in;
void inorder(TreeNode*root,int low ,int high){
    if(root==NULL){
        return;
    }
    inorder(root->left,low,high);
    if(root->val>=low && root->val<=high){
        in.push_back(root->val);
    }
    inorder(root->right,low,high);

}
TreeNode*construct(TreeNode*root,int low,int high,TreeNode*prev){
    if(root==NULL){
        return NULL;
    }
    
  
    root->left=construct(root->left,low,high,prev);
    
    root->right=construct(root->right,low,high,prev);
     if (root->val < low || root->val > high) {
        // If the current node is out of range, return its valid child.
        // If both children are NULL, return NULL to remove this node.
        return (root->left != NULL) ? root->left : root->right;
    }
    return root;
}

    


    TreeNode* trimBST(TreeNode* root, int low, int high) {
   TreeNode*prev=NULL;
        return construct(root,low,high,prev);
        
    }
};