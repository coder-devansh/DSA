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
vector<string>ans;
void  find(TreeNode*root,string str){
    if(root==NULL){
        return;
    }
    if(root->left==NULL && root->right==NULL){
        str=str+(char)(root->val+'a');
        reverse(str.begin(),str.end());
        ans.push_back(str);
        return;
    }
    

    find(root->left,str+(char)('a'+root->val));
    find(root->right,str+(char)(root->val+'a'));

}
    string smallestFromLeaf(TreeNode* root) {
        if(root==NULL){
            return "";
        }
       string result="";
        if(root->left==NULL && root->right==NULL){
            result+=(char)(root->val+'a');
            return result;
        }
         find(root,"");
         sort(ans.begin(),ans.end());
         for(auto it:ans) cout<<it<<" ";
         
         return ans[0];

        
    }
};