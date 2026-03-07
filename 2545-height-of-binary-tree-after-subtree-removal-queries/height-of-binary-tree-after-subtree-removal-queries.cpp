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
unordered_map<int,multiset<int>>mp;
unordered_map<int,int>height;
unordered_map<int,int>levels;
int find(TreeNode*root,int level){
    if(root==NULL)return 0;
    
    levels[root->val]=level;
    int lh=find(root->left,level+1);
    int rh=find(root->right,level+1);
    height[root->val]=max(lh,rh)+1;
    mp[level].insert(height[root->val]);
    
    return max(lh,rh)+1;
}
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        
        find(root,0);
        
        vector<int>ans;
        for(int i=0;i<queries.size();i++){
            int level=levels[queries[i]];
            int maxi=0;
            multiset<int>&st=mp[level];
            auto it = st.find(height[queries[i]]);
            st.erase(it);
            if(st.size()>0){
                int ele=*st.rbegin();
               ans.push_back(ele+level-1);
            }else{
                ans.push_back(level-1);

            }
            st.insert(height[queries[i]]);
            


        }
        return ans;
        
    }
};