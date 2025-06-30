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
TreeNode*find(TreeNode*root,int val){
    if(root==NULL)return root;
    if(root->val==val)return root;
    TreeNode*left=NULL;
    TreeNode*right=NULL;
    if(val<root->val){
        left=find(root->left,val);
    }else{
        right=find(root->right,val);
    }
    return left!=NULL?left:right;
}
    TreeNode* searchBST(TreeNode* root, int val) {
        return find(root,val);
        
    }
};