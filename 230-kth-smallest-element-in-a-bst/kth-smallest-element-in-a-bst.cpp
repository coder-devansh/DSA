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
void store_list(TreeNode*root,vector<int>&temp){
    if(root==NULL){
        return;
    }
    store_list(root->left,temp);
    temp.push_back(root->val);
    store_list(root->right,temp);
   
}
    int kthSmallest(TreeNode* root, int k) {
        vector<int>temp;
        store_list(root,temp);
        for(auto it:temp)cout<<it<<" ";
       if(k-1<0 || k-1>temp.size())return 0;
       return temp[k-1];
        

        
    }
};