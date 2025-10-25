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
vector<TreeNode*>ans;
TreeNode*find(TreeNode*root,unordered_map<int,int>mp){
    if(root==NULL){
        return root;
    }
    root->left=find(root->left,mp);
    root->right=find(root->right,mp);
    if(mp.find(root->val)!=mp.end()){
        if(root->left!=NULL){
            ans.push_back(root->left);
        }
        if(root->right!=NULL){
            ans.push_back(root->right);
        }
        return NULL;
    }
    return root;

}
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_map<int,int>mp;
        for(auto it:to_delete)mp[it]++;
        TreeNode*node=(find(root,mp));
        if(node!=NULL){
            ans.push_back(node);
        }
        return ans;
        
    }
};