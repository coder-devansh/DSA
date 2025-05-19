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
int sum=0;
void find(TreeNode*root,int h,int height){
    if(root==NULL){
        return;
    }
    if(root->left==NULL && root->right==NULL && h==height){
        sum+=root->val;
        return;
    }
    find(root->left,h+1,height);
    find(root->right,h+1,height);
}
int height(TreeNode*root){
    if(root==NULL){
        return 0;
    }
    int left=height(root->left);
    int right=height(root->right);
    return 1+max(left,right);

}

    int deepestLeavesSum(TreeNode* root) {
        int h=height(root);
        cout<<h<<endl;
        find(root,1,h);
        return sum;
    }
};