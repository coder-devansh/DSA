/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode oddEvenList(ListNode head) {
        if(head==null) return null;
        ListNode temp=head;
        ListNode prev=new ListNode(-1);
        ListNode dummy=prev;

        while(temp!=null){
            dummy.next=new ListNode(temp.val);
            dummy=dummy.next;
            if(temp.next==null){
                temp=temp.next;
            }else{
                 temp=temp.next.next;

            }
           
        


        }
        
        temp=head.next;
        while(temp!=null ){
            dummy.next=new ListNode(temp.val);
            dummy=dummy.next;
            if(temp.next==null){
                temp=temp.next;
            }else{
                 temp=temp.next.next;

            }
           
        }
        return prev.next;
    }
}