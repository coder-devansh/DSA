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
int maxi_diff;
void find(TreeNode*root,int mini,int maxi){
    if(root==NULL){
        return ;
    }
    maxi_diff=max(maxi_diff,abs(root->val-mini));
    maxi_diff=max(maxi_diff,abs(root->val-maxi));
    maxi=max(maxi,root->val);
    mini=min(mini,root->val);

    find(root->left,mini,maxi);
    find(root->right,mini,maxi);

    


}
    int maxAncestorDiff(TreeNode* root) {
        maxi_diff=INT_MIN;

     find(root,root->val,root->val);
     return maxi_diff;
        
    }
};