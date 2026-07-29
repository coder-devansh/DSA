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
    ListNode* deleteDuplicates(ListNode* head) {
        unordered_map<int,int>mp;
        ListNode*dummy=new ListNode(-1);
        dummy->next=head;
        head=dummy;
        ListNode*temp=head;
        while(temp!=NULL && temp->next!=NULL){
            
                mp[(temp->next->val)]++;
                    
                temp=temp->next;
            
        }
        temp=head;
         while(temp!=NULL && temp->next!=NULL){
            
            if(mp[(temp->next->val)]>=2)
            {
                temp->next=temp->next->next;
            }
            else{
                
                
                
                temp=temp->next;
            }
        }
       
        return head->next;
        
    }
};