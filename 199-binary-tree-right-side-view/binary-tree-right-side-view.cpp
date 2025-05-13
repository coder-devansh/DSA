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
vector<int>ans;

    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL){
            return {};
        }
       queue<TreeNode*>q;
       q.push(root);
       while(!q.empty()){
        int size=q.size();
        int data=0;
        for(int i=0;i<size;i++){
            auto it=q.front();
            q.pop();
            data=it->val;
            if(it->left!=NULL){
                q.push(it->left);
            }
            if(it->right!=NULL){
                q.push(it->right);
            }
        }
        ans.push_back(data);

       }
       return ans;
        
    }
};