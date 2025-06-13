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
ListNode*reverse(ListNode*head){
    ListNode*prev=NULL;
    ListNode*next=new ListNode(-1);
    ListNode*temp=head;
    while(temp!=NULL){
        ListNode*nextNode=temp->next;

        temp->next=prev;
        prev=temp;
        temp=nextNode;


    }
    return prev;
}
ListNode*find(ListNode*temp,int k){
    int count=1;
    while(temp!=NULL){
        if(count==k){
            return temp;
        }
        temp=temp->next;
        count++;
    }
    return NULL;

}
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode*prev=NULL;
        ListNode*temp=head;
        ListNode*nextNode=NULL;
        while(temp!=NULL){
            ListNode*kthNode=find(temp,k);
            if(kthNode==NULL){
                break;
            }
            ListNode*nextNode=kthNode->next;
            kthNode->next=NULL;
            reverse(temp);
            if(temp==head){
                head=kthNode;
            }else{
                prev->next=kthNode;
            }
            prev=temp;
            temp=nextNode;
        }
        if(temp!=NULL){
            prev->next=temp;
        }
        return head;
        
    }
};