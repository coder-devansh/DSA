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
vector<string>res;
int calculate(string str){
    long long sum=0;
    for(int i=0;i<str.size();i++){
        if(str[i]=='1'){
            sum+=pow(2,str.size()-i-1);
        }
        

    }
    return sum;
}
void find(TreeNode*&root,string str){
    if(root==NULL)return;
    if(root->left==NULL && root->right==NULL){
        str+=to_string(root->val);
        res.push_back(str);
        str.pop_back();
        return;
    }
    find(root->left,str+to_string(root->val));
    find(root->right,str+to_string(root->val));
}

    int sumRootToLeaf(TreeNode* root) {
        long long sum=0;
        find(root,"");
        for(auto it:res){
           
            sum+=calculate(it);
        }

        return sum;
    }
};