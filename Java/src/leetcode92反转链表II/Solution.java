package leetcode92反转链表II;

import share.ListNode;

/**
 * 使用递归的思路完成链表反转
 */

public class Solution {
    public ListNode reverseBetween(ListNode head, int left, int right) {

        if (left == 1) {
            return reverseN(head, right);
        }
        head.next = reverseBetween(head.next, left - 1, right - 1);
        return head;
    }

    /**
     * 反转整个链表
     * @param head
     * @return 反转链表的头结点
     */
    public ListNode reverse(ListNode head) {
        if (head.next == null) {
            return head;
        }
        ListNode last = reverse(head.next);
        head.next.next = head;
        head.next = null;
        return last;
    }

    /**
     * 反转链表的前n个
     * @param head
     * @param n
     * @return 反转
     */

    ListNode successor = null;
    public ListNode reverseN(ListNode head, int n) {
        if (n == 1) {
            successor = head.next;
            return head;
        }
        ListNode last = reverseN(head.next, n-1);
        head.next.next = head;
        head.next = successor;
        return last;
    }

}
