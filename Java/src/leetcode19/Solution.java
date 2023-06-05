package leetcode19;

import share.ListNode;

/**
 * 删除单链表倒数第N个结点
 * 只允许遍历一遍单链表实现
 */

public class Solution {

    /**
     * dummy -> 1
     * 使用前后指针
     * 注意只有一个结点，但是要删除倒数第一个结点
     * 需要辅助指针 位于head之前
     */

    public ListNode removeNthFromEnd(ListNode head, int n) {
        if(head == null){
            return null;
        }
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode fast = dummy;
        ListNode slow = dummy;
        for (int i = 0; i < n && fast != null; i++) {
            fast = fast.next;
        }
        if(fast != null){
            while(fast.next != null){
                fast = fast.next;
                slow = slow.next;
            }
        }

        //遍历完毕后slow指向要删除结点的前一个结点
        ListNode delete = slow.next;
        slow.next = delete.next;

        return dummy.next;
    }
}
