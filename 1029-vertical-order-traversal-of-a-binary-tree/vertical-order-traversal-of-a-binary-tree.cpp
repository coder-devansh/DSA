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
map<int,vector<int>>mp;
 map<int,map<int,multiset<int>>>match;
void find(TreeNode*root,int row,int col){
    if(root==NULL){
        return ;
    }
    mp[col].push_back(root->val);
    match[col][row].insert(root->val);
    find(root->left,row+1,col-1);
    find(root->right,row+1,col+1);

}

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
      find(root,0,0);
      vector<vector<int>>result;
      for(auto it:match){
        vector<int>ans;
        for(auto q:it.second){
            ans.insert(ans.end(),q.second.begin(),q.second.end());
        }
            result.push_back(ans);
      }

    //   for(auto it:mp){
    //     vector<int>ans;
    //     auto vec=it.second;
    //     for(auto it:vec){
    //         col.insert(col.end(),it);
            
    //     }
        
    //     result.push_back(ans);
    //     cout<<endl;
    //   }
      return result;
        
    }
};