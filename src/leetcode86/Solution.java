package leetcode86;

import share.ListNode;

public class Solution {
    public ListNode partition(ListNode head, int x) {
        ListNode dummy1 = new ListNode(0);
        ListNode dummy2 = new ListNode(0);

        ListNode node1 = dummy1;
        ListNode node2 = dummy2;
        ListNode current = head;
        while (current != null){
            if(current.val < x){
                node1.next = current;
                node1 = node1.next;
            }else{
                node2.next = current;
                node2 = node2.next;
            }
            current = current.next;
        }
        node1.next = dummy2.next;
        node2.next = null;
        return dummy1.next;
    }
}
