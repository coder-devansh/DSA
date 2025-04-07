/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
TreeNode*lca(TreeNode*root,TreeNode*p,TreeNode*q){
    if(root==p || root==q){
        return root;
    }
    if(root==NULL){
        return NULL;
    }
    auto left=lca(root->left,p,q);
    auto right=lca(root->right,p,q);
    if(left!=NULL && right!=NULL) return root;
    if(left!=NULL && right==NULL) return left;
    return right;
}
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return lca(root,p,q);

        
    }
};