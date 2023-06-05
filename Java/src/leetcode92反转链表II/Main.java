package leetcode92反转链表II;

import share.ListNode;

public class Main {
    public static void main(String[] args) {
        Solution solution = new Solution();
        ListNode a5 = new ListNode(5);
        ListNode a4 = new ListNode(4,a5);
        ListNode a3 = new ListNode(3,a4);
        ListNode a2 = new ListNode(2,a3);
        ListNode a1 = new ListNode(1,a2);

        ListNode res = solution.reverse(a1);
        System.out.println("123");

    }
}
