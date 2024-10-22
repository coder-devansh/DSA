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
vector<TreeNode*>fun(int n,int start,int end){
     vector<TreeNode*>ans;
    if(start>end){
        ans.push_back(NULL);
        return ans;
    }
   
    for(int i=start;i<=end;i++){
        for(auto it:fun(n,start,i-1))
        {
            for(auto j:fun(n,i+1,end))
            {
                TreeNode*root=new TreeNode(i,it,j);
                ans.push_back(root);
            }
        }
    }
    return ans;
}
    vector<TreeNode*> generateTrees(int n) {
        int start=1;
        int end=n;
       return  fun(n,start,end);

        
    }
};