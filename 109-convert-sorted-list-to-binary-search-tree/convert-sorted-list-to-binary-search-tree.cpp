/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
TreeNode*fun(int low,int high,vector<int>arr)
{
    if(low>high){
        return NULL;
    }
    int mid=(low+high)/2;
    TreeNode*root=new TreeNode(arr[mid]);
    root->left=fun(low,mid-1,arr);
    root->right=fun(mid+1,high,arr);

    return root;
    

}
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int>arr;
        ListNode*temp=head;
        while(temp!=NULL){
            arr.push_back(temp->val);
            temp=temp->next;
        }
        int low=0;
        int high=arr.size()-1;

       return fun(low,high,arr);
    

        
    }
};