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
bool find(TreeNode*root,int target,map<int,int>&mp){
    if(root==NULL){
        return false;
    }
    bool left=find(root->left,target,mp);
    if(mp.find(target-root->val)!=mp.end())return true;
    mp[root->val]++;
    bool right=find(root->right,target,mp);
    return left || right;

}

    bool findTarget(TreeNode* root, int k) {
        map<int,int>mp;
        return find(root,k,mp);
        
    }
};