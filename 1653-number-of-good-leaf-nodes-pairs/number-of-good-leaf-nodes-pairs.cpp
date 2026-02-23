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
 #define ll long long
class Solution {
public:
int count1=0;
vector<TreeNode*>leaf;
map<TreeNode*,vector<TreeNode*>>mp;
void find(TreeNode*&root,vector<vector<int>>&adj,int parent){
    if(root==NULL)return ;
    if(root->left==NULL && root->right==NULL){
        leaf.push_back(root);
    }
    if(root->left!=NULL){
        mp[root].push_back(root->left);
        mp[root->left].push_back(root);

    }
    if(root->right!=NULL){
        mp[root].push_back(root->right);
        mp[root->right].push_back(root);

    }
    
    find(root->left,adj,root->val);
    find(root->right,adj,root->val);
}

void find_pair(TreeNode*node,int depth ,int distance,map<TreeNode*,int>&vis){
    if(depth>distance)return;
    if((node->left==NULL && node->right==NULL) && depth<=distance && !vis[node]){
        count1++;
        return;
        
    }
    
    vis[node]++;
    for(auto it:mp[node]){
        if(vis.find(it)==vis.end()){
            find_pair(it,depth+1,distance,vis);
        }
    }

}



    int countPairs(TreeNode* &root, int distance) {
        vector<vector<int>>adj(101);
        find(root,adj,-1);
        for(int i=0;i<leaf.size();i++){
            map<TreeNode*,int>vis;
            vis[leaf[i]]++;
            find_pair(leaf[i],0,distance,vis);
        }
        return count1/2;
        

        
    }
};