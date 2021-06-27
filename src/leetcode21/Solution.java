package leetcode21;

import share.ListNode;

import java.util.Comparator;
import java.util.PriorityQueue;

/**
 * 合并有序链表
 */

public class Solution {
    /**
     * 合并两个排序链表
     * @param l1
     * @param l2
     * @return
     */
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {

        if(l2 == null){
            return l1;
        }
        if(l1 == null){
            return l2;
        }
        ListNode result;

        if(l1.val < l2.val){
            result = l1;
            result.next = mergeTwoLists(l1.next,l2);

        } else {
            result = l2;
            result.next = mergeTwoLists(l1,l2.next);

        }
        return result;
    }

    /**
     * 合并k个排好序的链表
     * @param lists
     * @return
     */
    public ListNode mergeKLists(ListNode[] lists) {

        if(lists == null){
            return null;
        }
        ListNode dummyHead = new ListNode(0);
        ListNode cur = dummyHead;

//        //优先队列，自定义比较器
//        PriorityQueue<ListNode> priorityQueue = new PriorityQueue<>(
//                new Comparator<ListNode>() {
//                    @Override
//                    public int compare(ListNode o1, ListNode o2) {
//                        return o1.val - o2.val;
//                    }
//                }
//        );
        PriorityQueue<ListNode> priorityQueue = new PriorityQueue<>((o1, o2) -> o1.val-o2.val);

        //将K个链表加入到优先队列中
        for (ListNode list : lists) {
            if (list == null) {
                continue;
            }
            priorityQueue.add(list);
        }

        while(!priorityQueue.isEmpty()){
            ListNode nextNode = priorityQueue.poll();
            cur.next = nextNode;
            cur = cur.next;
            //如果出优先队列的结点所在链表还有结点
            if(nextNode.next!=null){
                priorityQueue.add(nextNode.next);
            }
        }

        return dummyHead.next;

    }

    /**
     * 分治算法
     * 结合归并思想，以及两个链表合并
     */

    public ListNode mergeKLists1(ListNode[] lists){
        if (lists == null || lists.length == 0){
            return null;
        }
        return merge(lists,0,lists.length - 1);
    }

    private ListNode merge(ListNode[] lists, int left, int right) {
        if (left == right) {
            return lists[left];
        }
        int mid = (left + right) / 2;

        ListNode l1 = merge(lists, left, mid);
        ListNode l2 = merge(lists, mid + 1, right);
        return mergeTwoLists(l1, l2);
    }

}
