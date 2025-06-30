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
    if(root==NULL)return root;
    if(root->val==p->val || root->val==q->val)return root;
    auto left=lca(root->left,p,q);
    auto right=lca(root->right,p,q);
    if(left!=NULL && right!=NULL)return root;
    return left==NULL?right:left;
}
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return lca(root,p,q);
        
    }
};