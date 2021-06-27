package leetcode83;

import share.ListNode;

public class Main {
    public static void main(String[] args) {
        ListNode l1 = new ListNode(0);
        ListNode l2 = new ListNode(0);
        ListNode l3 = new ListNode(0);
        ListNode l4 = new ListNode(1);
        ListNode l5 = new ListNode(2);
        ListNode l6 = new ListNode(2);
        ListNode l7 = new ListNode(4);
        l1.next = l2;
        l2.next = l3;
        l3.next = l4;
        l4.next = l5;
        l5.next = l6;
        l6.next = l7;
        Solution solution = new Solution();
//        ListNode withoutDuplicates = solution.deleteDuplicates(l1);
//
//        while(withoutDuplicates != null){
//            System.out.print(withoutDuplicates.val + " ");
//            withoutDuplicates = withoutDuplicates.next;
//        }

//        ListNode only = solution.deleteDuplicatesOnly(l1);
//        while (only != null){
//            System.out.print(only.val + " ");
//            only = only.next;
//        }
        ListNode unSorted = solution.deleteDuplicatesInNoSortedList(l1);
        while (unSorted != null){
            System.out.print(unSorted.val+ " ");
            unSorted = unSorted.next;
        }
    }
}
