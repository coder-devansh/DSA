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
TreeNode*dfs(TreeNode*root,TreeNode*p,TreeNode*q){
    if(root==NULL)return NULL;
    if(root==p)return root;
    if(root==q)return root;
    auto left=dfs(root->left,p,q);
    auto right=dfs(root->right,p,q);
    if(left!=NULL && right!=NULL)return root;
    if(left!=NULL)return left;
    return right;
}
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return dfs(root,p,q);
        
    }
};