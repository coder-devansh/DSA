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
TreeNode*find_lca(TreeNode*root,int len,int h){
    if(len==h-1){
        return root;
    }
    if(root==NULL) return NULL;
    auto left=find_lca(root->left,len+1,h);
    auto right=find_lca(root->right,len+1,h);
    if(left!=NULL && right!=NULL) return root;
    if(left!=NULL && right==NULL) return left;
    return right;
}
int height(TreeNode*root){
    if(root==NULL) return 0;
    int left=height(root->left);
    int right=height(root->right);
    return max(left,right)+1;
}
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int h=height(root);
        return find_lca(root,0,h);
        
    }
};