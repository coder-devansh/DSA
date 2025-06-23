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
int maxi;
int find(TreeNode*root){
    if(root==NULL){
        return 0;
    }
    int leftSum=max(0,find(root->left));
    int rightSum=max(0,find(root->right));
    maxi=max(maxi,root->val+leftSum+rightSum);
   
    return max(leftSum,rightSum)+root->val;
}
    int maxPathSum(TreeNode* root) {
        maxi=INT_MIN;
         find(root);
         return maxi;
        
    }
};