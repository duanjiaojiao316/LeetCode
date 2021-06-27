package leetcode86;

import share.ListNode;

public class Main {
    public static void main(String[] args) {
        ListNode l1 = new ListNode(5);
        ListNode l2 = new ListNode(2);
        ListNode l3 = new ListNode(4);
        ListNode l4 = new ListNode(6);
        ListNode l5 = new ListNode(2);
        ListNode l6 = new ListNode(1);
        ListNode l7 = new ListNode(0);
        l1.next = l2;
        l2.next = l3;
        l3.next = l4;
        l4.next = l5;
        l5.next = l6;
        l6.next = l7;
        Solution solution = new Solution();
        ListNode listNode = solution.partition(l1,3);
        while (listNode != null){
            System.out.print(listNode.val+ " ");
            listNode = listNode.next;
        }
    }
}
