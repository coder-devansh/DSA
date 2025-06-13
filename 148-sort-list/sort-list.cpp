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
ListNode*findmid(ListNode*head){
    ListNode*slow=head;
    ListNode*fast=head;
    while(fast->next!=NULL && fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
ListNode*merge(ListNode*left,ListNode*right){
    ListNode*temp=new ListNode(-1);
    ListNode*ans=temp;
    if(left == NULL) return right;
if(right == NULL) return left;
    while(left!=NULL && right!=NULL){
        if(left->val<right->val){
            ans->next=left;
            ans=ans->next;
            left=left->next;
            
        }else{
            ans->next=right;
            ans=ans->next;
            right=right->next;
        }
    }
    while(left!=NULL){
        ans->next=left;
        ans=ans->next;
        left=left->next;
    }
    while(right!=NULL){
        ans->next=right;
        ans=ans->next;
        right=right->next;
    }
    return temp->next;
}
ListNode*mergeSort(ListNode*head){
    if(head==NULL || head->next==NULL){
        return head;
    }

    ListNode*mid=findmid(head);
    ListNode*left=head;
    ListNode*right=mid->next;
    mid->next=NULL;
    left=mergeSort(left);
    right=mergeSort(right);

    ListNode*result=merge(left,right);
    return result;
}
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL)return head;
        return mergeSort(head);
        
    }
};