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
int maxi=0;
int  find(TreeNode*root,int parent){
    if(root==NULL){
        return 0;
    }
    int left=find(root->left,root->val);
    int right=find(root->right,root->val);
    maxi=max(maxi,(left+right));
    return root->val==parent?max(left,right)+1:0;
  
}

    int longestUnivaluePath(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        if(root->left==NULL && root->right==NULL){
            return 0;
        }
    int val= find(root,-1);
    return maxi;
        
    }
};