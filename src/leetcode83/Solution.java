package leetcode83;

import share.ListNode;

import java.util.HashSet;


/**
 * 删除已排序链表中的重复结点
 */

public class Solution {

    /**
     * 删除已排序链表中的重复结点，把重复的数字只留下一个
     */

    public ListNode deleteDuplicates(ListNode head) {
        if(head == null){
            return null;
        }
        ListNode cur = head;
        ListNode next;
        while(cur != null &&cur.next != null){
            if(cur.val== cur.next.val){
                //next为重复结点
                next = cur.next;
                //cur.next跳过next结点
                cur.next = next.next;
                //更新cur
                //重复结点删除
                next = null;
                continue;
            }else{
                cur = cur.next;
            }

        }
        return head;
    }


    /**
     * 给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字。
     */

    public ListNode deleteDuplicatesOnly(ListNode head) {
        ListNode dummy = new ListNode(Integer.MIN_VALUE);
        dummy.next = head;
        ListNode current = head;
        ListNode start = dummy;
        ListNode end = dummy;
        // 1 -> 1 ->2 ->
        while(current != null && current.next != null){
            //当前结点与下一个结点不相等，需要更新start
            if(current.val != current.next.val){
                start = start.next;
                current = current.next;
                continue;
            }
            //如果当前结点与下一个结点相同,start不更新，需要找到相同节点中的最后一个结点
            while( current.next != null && current.val== current.next.val){
                current = current.next;
            }
            //获取不相同的数字的结点
            end = current.next;
            //删除相同的结点
            start.next = end;
            //更新相同结点的起点
            current = current.next;


        }
        return dummy.next;
    }

    /**
     * 删除无须链表中重复出现的结点
     * 使用哈希表
     */
    public ListNode deleteDuplicatesInNoSortedList(ListNode head){

        if (head == null){
            return null;
        }
        HashSet<Integer> hashSet = new HashSet<>();
        ListNode cur = head;
        hashSet.add(cur.val);
        ListNode pre = cur;
        cur = cur.next;
        while (cur != null){
            if(hashSet.contains(cur.val)){
                pre.next = cur.next;
            }else{
                hashSet.add(cur.val);
                pre = cur;
            }
            cur = cur.next;
        }
        return head;
    }

}

