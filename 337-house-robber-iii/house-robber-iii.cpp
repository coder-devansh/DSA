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
pair<int,int>find_money(TreeNode*root){
    if(root==NULL){
        return {0,0};
    }
    auto left=find_money(root->left);
    auto right=find_money(root->right);
    int exclude1=left.second;
    int exclude2=right.second;
    return {root->val+exclude1+exclude2,max(left.first,left.second)+max(right.first,right.second)};
}

    int rob(TreeNode* root) {
        auto val=find_money(root);
        return max(val.first,val.second);
        
    }
};