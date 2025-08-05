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
pair<int,int>fun(TreeNode*root,int sum){
    if(root==NULL){
        return {0,0};
    }
    auto left=fun(root->left,sum);
    auto right=fun(root->right,sum);
    int la=left.first;
    int lb=left.second;
    int ra=right.first;
    int rb=right.second;
    return {root->val+lb+rb,max(la,lb)+max(ra,rb)};
   
}
    
int rob(TreeNode* root) {
   auto it=fun(root,0);
   cout<<it.first<<" "<<it.second<<endl;
   return max(it.first,it.second);


       

        
    }
};