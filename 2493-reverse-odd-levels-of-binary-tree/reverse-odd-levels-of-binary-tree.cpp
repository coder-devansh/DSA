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
int level;
vector<int>temp;
void dfs(TreeNode*root){
    if(root==NULL){
        return;
    }
    dfs(root->left);
    dfs(root->right);
   
   

}
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int odd=1;
        vector<int>store;
        while(!q.empty()){
            int t=q.size();
            while(t--){
                TreeNode*node=q.front();
                q.pop();
                if(node->left){
                    q.push(node->left),store.push_back(node->left->val);
                }
                if(node->right){
                    q.push(node->right),store.push_back(node->right->val);
                }
                
            }
            if(odd & store.size()>0){
                int i=store.size()-1;
                t=q.size();
                while(t--){
                    TreeNode*node=q.front();
                    q.pop();
                    node->val=store[i--];
                    q.push(node);
                } 
                
            }
            odd=1-odd;
            

           
        }
        return root;


        }
    
};