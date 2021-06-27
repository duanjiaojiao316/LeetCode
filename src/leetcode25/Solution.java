package leetcode25;

import share.ListNode;


/**
 * 单链表反转
 */

public class Solution {
    /**
     * 反转单链表一个结点为一组
     * @param head 单链表头指针
     * @return 反转后的单链表头指针
     */
    public ListNode reverse(ListNode head){
        ListNode pre = null;
        ListNode current = head;
        ListNode next;
        while(current != null){
            //记录当前结点的next
            next = current.next;
            //更新当前结点的next为pre结点
            current.next = pre;
            //pre 和 current的更新
            pre = current;
            current = next;
        }
        return pre;
    }

    /**
     * 给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。
     * 如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
     * @param k k 是一个正整数，它的值小于或等于链表的长度。
     * @param head 头结点
     * @return 反转后的链表
     */
    public ListNode reverseKFromHead(int k, ListNode head){
        //pre 为以k个结点为一组的起始结点的前一个结点，由于head结点之前没有结点所以创建一个pre结点
        ListNode zero = new ListNode(0);
        //pre新节点指向head
        zero.next = head;
        ListNode pre = zero;
        //start 为以k个结点为一组的起始结点
        ListNode start = head;
        //end 为以k个结点为一组的结尾结点
        ListNode end = pre;
        ListNode next;
        while(start != null){
            for (int i = 0; i < k && end !=null; i++) {
                end = end.next;
            }
            if(end == null){
                break;
            }
            //记录后继结点
            next = end.next;
            //暂时斩断后继结点的连接
            end.next = null;
            //前驱连接
            pre.next = reverse(start);
            //后继结点连接
            start.next = next;
            //指针更新准备下一轮反转

            pre = start;
            end = pre;
            start = start.next;
        }
        return zero.next;
    }

    /**
     * 从单链表的尾结点开始，以k个结点为1组，反转
     * @param k k是一个整数，它的值小于或等于链表的长度。
     * @param head 单链表头指针
     * @return 反转后的单链表
     */
    public ListNode reverseKFromTail(int k, ListNode head){
        int size = getSize(head);
        int offset = size % k;
        ListNode pre = head;
        for (int i = 0; i < offset - 1; i++) {
            pre = pre.next;
        }
        pre.next = reverseKFromHead(k, pre.next);
        return head;
    }

    /**
     * 单链表两个结点为一组反转
     * @param head 单链表头结点
     * @return 反转后的头结点
     */

    public ListNode reverseTwo(ListNode head){
        ListNode zero = new ListNode(0);
        zero.next = head;
        ListNode pre = zero;
        ListNode next;
        while(pre.next != null && pre.next.next!=null){
            next = pre.next.next.next;
            ListNode a = pre.next;
            ListNode b = pre.next.next;
            //反转
            pre.next = b;
            b.next = a;
            a.next = next;
            //更新pre
            pre = a;
        }
        return zero.next;
    }


    /**
     * 求当链表size
     */
    public int getSize(ListNode head){
        int count = 0;
        while(head != null){
            count++;
            head = head.next;
        }
        return count;
    }

}

