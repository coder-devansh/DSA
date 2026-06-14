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
class Solution {
public:
    int pairSum(ListNode* head) {
        if(head==NULL)return 0;
        if(head->next==NULL)return head->val;
        vector<int>arr;
        while(head!=NULL){
            arr.push_back(head->val);
            head=head->next;
        }
        int low=0;
        int high=arr.size()-1;
        int sum=0;
        while(low<high){
            sum=max(sum,(arr[low]+arr[high]));
            low++;
            high--;
        }
        return sum;


        
    }
};