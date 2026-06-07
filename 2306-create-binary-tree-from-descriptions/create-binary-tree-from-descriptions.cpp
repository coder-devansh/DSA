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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {

        set<int>st;
        TreeNode*root;
        vector<vector<pair<int,int>>>adj(1e5+1);
        for(auto it:descriptions){
            int parent=it[0];
            int child=it[1];
            int status=it[2];
            adj[it[0]].push_back({it[1],it[2]});
            st.insert(it[1]);
        }
        for(auto it:descriptions){
            if(st.find(it[0])==st.end()){
                root=new TreeNode(it[0]);
                break;
            }
        }
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            for(auto ele:adj[it->val])
            {
                int child=ele.first;
                int status=ele.second;
                if(status==1){
                    it->left=new TreeNode(child);
                    q.push(it->left);
                }
                else{
                    it->right=new TreeNode(child);
                    q.push(it->right);
                }
                

            }
        }
        return root;


        
    }
};