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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
       ListNode*head=new ListNode(-1);
       ListNode*temp=head;
        while(list1!=NULL && list2!=NULL){
            if(list1->val<=list2->val){
                ListNode*val=new ListNode(list1->val);
                temp->next=val;
                temp=val;
                list1=list1->next;
            }
            else{
                ListNode*val=new ListNode(list2->val);
                temp->next=val;
                temp=val;
                list2=list2->next;
            }
        }
        while(list1!=NULL){
            ListNode*val=new ListNode(list1->val);
            temp->next=val;
            temp=val;
            list1=list1->next;
        }
        while(list2!=NULL){
            ListNode*val=new ListNode(list2->val);
            temp->next=val;
            temp=val;
            list2=list2->next;
        }
        return head->next;

        
    }
};