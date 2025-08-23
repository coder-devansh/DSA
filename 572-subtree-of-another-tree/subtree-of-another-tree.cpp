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
bool isIdentical(TreeNode*root,TreeNode*subroot){
    if(subroot==NULL && root==NULL)return true;
    if(root==NULL || subroot==NULL)return false;
    if(root->val!=subroot->val){
        return false;
    }
    return isIdentical(root->left,subroot->left) && isIdentical(root->right,subroot->right);
}
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(subRoot==NULL){
            return true;
        }
        if(root==NULL || subRoot==NULL)return false;
        if(root->val==subRoot->val){
            if(isIdentical(root,subRoot))return true;
        }
        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
        
    }
};