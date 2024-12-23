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
int start;
int count=0;

void fin(vector<int>values){
 vector<int>target(values);
 sort(target.begin(),target.end());
unordered_map<int,int>pos;
for(int i=0;i<values.size();i++){
    pos[values[i]]=i;
}
for(int i=0;i<values.size();i++){
    if(values[i]!=target[i])
    {
        count++;
        int po=pos[target[i]];
        pos[values[i]]=po;
        swap(values[i],values[po]);
    }
}
   
}

    int minimumOperations(TreeNode* root) {
        
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            vector<int>values;
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode*node=q.front();
                q.pop();
                values.push_back(node->val);
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
          fin(values);
        }
        
        
           
        
        return count;
       
    }
};