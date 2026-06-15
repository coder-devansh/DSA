/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
 unordered_map<TreeNode*,TreeNode*>mp;
void dfs(TreeNode*root){
    if(root==NULL)return;
    mp[root->left]=root;
    mp[root->right]=root;
    dfs(root->left);
    dfs(root->right);
}
vector<int>vis;
vector<int>ans;

void find_nodes(TreeNode*target,int k){
    if(target==NULL)return;
    if(k==0){
        ans.push_back(target->val);
        return;
    }
    if(k<0)return;
    if(target!=NULL){
    TreeNode*parent=mp[target];
    if(parent!=NULL){
    if(vis[parent->val]==0){
        vis[parent->val]=1;
        find_nodes(parent,k-1);
    }
    }
    }
    if(target->left!=NULL){
        if(!vis[target->left->val]){
            vis[target->left->val]++;
            find_nodes(target->left,k-1);

        }
    }
    if(target->right!=NULL){
         if(!vis[target->right->val]){
            vis[target->right->val]++;
            find_nodes(target->right,k-1);

        }

    }
    
   
    

}
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
       vis.resize(501,0);
        mp[root]=NULL;
        dfs(root);
        vis[target->val]++;
        find_nodes(target,k);
        return ans;



        
        
    }
};