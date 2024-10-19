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
vector<int>in;
void inorder(TreeNode*root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    in.push_back(root->val);
    inorder(root->right);
}
vector<vector<int>>ans;
void findmin(int value,vector<int>&nums){
    vector<int>result;
    int low=0;
    int mini=INT_MIN;
    int maxi=INT_MAX;
    int high=nums.size()-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(nums[mid]==value){
            mini=value;
            maxi=value;
            break;
        }
        if(nums[mid]<value){
            mini=nums[mid];
            low=mid+1;
        }
        else if(nums[mid]>value){ 
            
            maxi=nums[mid];
           
            high=mid-1;
           

        }
         
        
        }
          if (mini == INT_MIN) mini = -1;
        // If no larger value found, set maxi to -1
        if (maxi == INT_MAX) maxi = -1;
        
        ans.push_back({mini,maxi});
        
    }

    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        inorder(root);
        
       for(int i:queries){
        findmin(i,in);
        }
        return ans;
        
        
    }
};