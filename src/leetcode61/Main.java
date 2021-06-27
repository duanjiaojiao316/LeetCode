package leetcode61;

import share.ListNode;

public class Main {
    public static void main(String[] args) {
        ListNode listNode1 = new ListNode(1);
        ListNode listNode2 = new ListNode(2);
        ListNode listNode3 = new ListNode(3);
        ListNode listNode4 = new ListNode(4);
        ListNode listNode5 = new ListNode(5);
        listNode1.next = listNode2;
        listNode2.next = listNode3;
        listNode3.next = listNode4;
        listNode4.next = listNode5;
        Solution solution = new Solution();
        ListNode newStart = solution.rotateRight(listNode1,0);
        while(newStart != null){
            System.out.print(newStart.val + " ");
            newStart = newStart.next;
        }
        System.out.println();

        ListNode newStart1 = solution.rotateRight(listNode4, 1);
        while(newStart1 != null){
            System.out.print(newStart1.val + " ");
            newStart1 = newStart1.next;
        }
    }


}
