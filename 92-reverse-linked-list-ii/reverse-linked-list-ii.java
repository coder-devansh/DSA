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

    public ListNode reverse(ListNode curr,ListNode prev,ListNode dist){
        if(curr==null){
            return prev;
        }
        ListNode temp=curr.next;
        curr.next=prev;
        prev=curr;
        
        return reverse(temp,prev,dist);

    }
    public ListNode reverseBetween(ListNode head, int left, int right) {
        if(head==null && head.next==null){
            return head;
        }
        ListNode curr=null;
        ListNode dest=null;
        ListNode temp=head;
        ListNode dummy=null;
        int index=1;
        while(temp!=null){
            if(index==left){
                curr=temp;
                dummy=curr;
                
            }
            if(index==right){
                 dest=temp.next;
                dummy.next=null;
               
                
            }
            if(dummy!=null && dummy.next!=null){
                dummy=dummy.next;
            }
            temp=temp.next;
            index++;

        }
         ListNode val=reverse(curr,null,dest);
          index=0;
         ListNode ter=new ListNode(-1);
         ter.next=head;
         head=ter;
         while(ter.next!=null){
            if(index==left-1){
                ter.next=null;
                ter.next=val;
            }
            ter=ter.next;
            index++;
           
         }
         ter.next=dest;
         
        
         return head.next;

        
        
    }
}