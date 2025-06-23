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
map<int,map<int,multiset<int>>>mp;
void find(int row,int col,TreeNode*root){
    if(root==NULL){
        return;
    }
    mp[col][row].insert(root->val);
    find(row+1,col-1,root->left);
    find(row+1,col+1,root->right);
}

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        find(0,0,root);
        vector<vector<int>>result;
        for(auto it:mp){
            vector<int>ans;
            for(auto q:it.second){
                ans.insert(ans.end(),q.second.begin(),q.second.end());

            }
            result.push_back(ans);
        }
        return result;
        
    }
};