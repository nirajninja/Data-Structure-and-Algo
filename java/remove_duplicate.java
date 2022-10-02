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
    public ListNode deleteDuplicates(ListNode head) {
        ListNode current=head;
        ListNode pnext;
        
        if(head==null || head.next==null) return head;
        else
        {
            pnext=current.next;
            while(pnext!=null)
            {
                if(current.val==pnext.val){
                    pnext=pnext.next;
                    continue;
                    }
                else{
                    current.next=pnext;
                    pnext=pnext.next;
                    current=current.next;
                    }
                }
            }
        
        if(current!=null && pnext==null){ current.next=null;}
    return head;
    }
    

}
