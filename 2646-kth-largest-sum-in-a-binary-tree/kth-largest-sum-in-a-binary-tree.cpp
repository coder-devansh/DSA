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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode*>q;
        if(root==NULL){
            return 0;
        }
        q.push(root);
        vector<long long >result;
        while(!q.empty()){
            int n=q.size();
            long long  sum=0;
            for(int i=0;i<n;i++)
            {
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
            result.push_back(sum);
           

        }
        sort(result.begin(),result.end());
if(k>result.size()){
    return -1;
}

int j=1;
for(int i=result.size()-1;i>=0;i--){
    if(j==k){
        return result[i];
        
    }
    j++;
}

        return -1;
    }
};