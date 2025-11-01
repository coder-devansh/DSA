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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int,int>mp;
        for(auto it:nums){
            mp[it]++;
        }
        ListNode*new_Head=new ListNode(-1);
        new_Head->next=head;
        ListNode*temp=new_Head;
        while(temp->next!=NULL){
           int val=temp->next->val;
           if(mp[val]>0){

            temp->next=temp->next->next;
           }else{
            temp=temp->next;
           }

        }
        return new_Head->next;
        
    }
};