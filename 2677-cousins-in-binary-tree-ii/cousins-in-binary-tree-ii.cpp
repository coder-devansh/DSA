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
void fun(TreeNode*root,int d){
   if(root==NULL){
    return ;
   }
   int children_sum=(root->left!=NULL?root->left->val:0)+(root->right!=NULL?root->right->val:0);
   if(root->left!=NULL){
    root->left->val=ans[d]-children_sum;
   }
   if(root->right!=NULL){
    root->right->val=ans[d]-children_sum;
   }
   fun(root->left,d+1);
   fun(root->right,d+1);

   


}
void find(TreeNode*root){
    queue<TreeNode*>q;
            q.push(root);
        int level=0;
        vector<int>sum;
        while(!q.empty()){
            int n=q.size();
           int sum=0;
            for(int i=0;i<n;i++){
                TreeNode*node=q.front();
                q.pop();
             
                
                     sum+=node->val;
               
                if(node->left!=NULL){
                    q.push(node->left);
                }
                if(node->right!=NULL){
                    q.push(node->right);
                }
            }
            ans.push_back(sum);

        }
}

    TreeNode* replaceValueInTree(TreeNode* root) {
        root->val=0;
                
 int d=1;

        find(root);
        fun(root,d);
        return root;


        
    }
};