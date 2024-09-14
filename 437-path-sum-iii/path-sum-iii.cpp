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
vector<int>list;
int count;
void fun(TreeNode*root,int x)
{
    if(root==NULL)

    {
        return;
    }
    list.push_back(root->val);
    fun(root->left,x);
    fun(root->right,x);
  long long  temp=0;
    for(int i=list.size()-1;i>=0;i--)
    {
        temp+=list[i];
        if(temp==x)
        {
            count++;
        }

    }
    list.pop_back();



}
    int pathSum(TreeNode* root, int targetSum) {
        if(root==NULL )
        {
            return 0;
        }
        
        fun(root,targetSum);
        return count;
     

        
    }
};