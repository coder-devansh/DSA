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

vector<TreeNode*>create(int start,int end){
    if(start>end){
        
        return {NULL};
    }
vector<TreeNode*>ans;
    for(int i=start;i<=end;i++){
        for(auto it:create(start,i-1))
        {
            for(auto j:create(i+1,end))
            {
                TreeNode*root=new TreeNode(i,it,j);
                ans.push_back(root);
            }
        }
    }
    return ans;


}

vector<TreeNode*> generateTrees(int n) {

return create(1,n);




        
    }
};