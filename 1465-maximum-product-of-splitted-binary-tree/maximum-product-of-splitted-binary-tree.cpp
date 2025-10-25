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
const int mod=(int)1e9+7;
long long find_sum(TreeNode*root,map<TreeNode*,long long>&mp,int i){
    if(root==NULL){
        return 0;
    }
    long long left=find_sum(root->left,mp,i-1);
    long long right=find_sum(root->right,mp,i+1);
    long long total = (left + right + root->val);
        mp[root] = total;
        return total;
}
    int maxProduct(TreeNode* root) {
        if(root==NULL)return 0;
        map<TreeNode*,long long>sum;
        long long total_sum=find_sum(root,sum,0);
        long long mx=1;
        for(auto it:sum){
            long long part = it.second;
            long long product = (part * ((total_sum - part) % mod));
            mx = max(mx, product);

        }
        return mx % mod;
        
    }
};