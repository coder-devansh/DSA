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
bool isValid(TreeNode*root,long long  minVal,long long maxVal){
    if(root==NULL){
        return true;
    }
    if(root->val<=minVal || root->val>=maxVal)return false;
    return isValid(root->left,minVal,root->val) && isValid(root->right,root->val,maxVal);
}

    bool isValidBST(TreeNode* root) {
        
      long long  minVal=LONG_MIN;
      long long  maxVal=LONG_MAX;
      return isValid(root,minVal,maxVal);
        
    }
};