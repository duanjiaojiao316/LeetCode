package leetcode61;

import share.ListNode;

public class Solution {

    /**
     * 1 -> 2 -> 3 -> 4 -> 5
     *
     */
    public ListNode rotateRight(ListNode head, int k) {
        if(head == null){
            return null;
        }
        int size = getSize(head);
        //将指针首位相连形成循环链表
        ListNode current = head;
        while(current.next != null){
            current = current.next;
        }
        current.next = head;
        //计算新链表的尾结点
        int tail = size - k%size - 1;
        current = head;
        for (int i = 0; i < tail ; i++) {
            current = current.next;
        }

        //新链表的头结点
        ListNode newStart = current.next;
        //去掉尾结点和头结点之间的链接
        current.next = null;

        return newStart;
    }

    private int getSize(ListNode head) {
        int count = 0;
        while (head != null){
            head = head.next;
            count++;
        }
        return count;
    }

}
