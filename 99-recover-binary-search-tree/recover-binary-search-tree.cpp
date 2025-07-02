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
// use the properties of inorder
void recover(TreeNode*root,TreeNode*&first,TreeNode*&second,TreeNode*&prev){
    if(root==NULL){
        return;
    }
    recover(root->left,first,second,prev);// use the inorder and check which two val 
    if(prev!=NULL && prev->val>root->val){
        if(first==NULL)first=prev;
        second=root;
    }
    prev=root;
    recover(root->right,first,second,prev);
}
    void recoverTree(TreeNode* root) {
        TreeNode*first=NULL;
        TreeNode*second=NULL;
        TreeNode*prev=NULL;
        recover(root,first,second,prev);
        if(first!=NULL && second!=NULL){
            swap(first->val,second->val);
        }
        
    }
};