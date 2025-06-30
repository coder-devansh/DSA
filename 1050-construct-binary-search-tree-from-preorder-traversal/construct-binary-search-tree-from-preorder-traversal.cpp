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
TreeNode*add(TreeNode*root,int val){
    if(root==NULL){
        return new TreeNode(val);
    }
    if(root->val>val){
       root->left= add(root->left,val);
       
        
    }else{
        root->right=add(root->right,val);
        
    }
    return root;


}
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        TreeNode*root=new TreeNode(preorder[0]);
        TreeNode*curr=root;
        for(int i=1;i<preorder.size();i++){
           
                add(root,preorder[i]);

        }
        return root;
        
    }
};