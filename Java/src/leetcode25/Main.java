package leetcode25;

import share.ListNode;

public class Main {
    public static void main(String[] args) {
        Solution solution = new Solution();
        ListNode listNode1 = new ListNode(1);
        ListNode listNode2 = new ListNode(2);
        ListNode listNode3 = new ListNode(3);
        ListNode listNode4 = new ListNode(4);
        ListNode listNode5 = new ListNode(5);
        ListNode listNode6 = new ListNode(6);
        ListNode listNode7 = new ListNode(7);
        ListNode listNode8 = new ListNode(8);
        ListNode listNode9 = new ListNode(9);
        ListNode listNode10 = new ListNode(10);
        listNode1.next = listNode2;
        listNode2.next = listNode3;
        listNode3.next = listNode4;
        listNode4.next = listNode5;
        listNode5.next = listNode6;
        listNode6.next = listNode7;
        listNode7.next = listNode8;
        listNode8.next = listNode9;
        listNode9.next = listNode10;
//        ListNode reverse  = solution.reverse(listNode1);
//        while (reverse != null){
//            System.out.print(reverse.value+" ");
//            reverse = reverse.next;
//        }
//        System.out.println();

//        ListNode reverseKFromHead = solution.reverseKFromHead(3,listNode1);
//        while (reverseKFromHead != null){
//            System.out.print(reverseKFromHead.value+" ");
//            reverseKFromHead = reverseKFromHead.next;
//        }

//        ListNode reverseKFromTail = solution.reverseKFromTail(3,listNode1);
//        while (reverseKFromTail != null){
//            System.out.print(reverseKFromTail.value+" ");
//            reverseKFromTail = reverseKFromTail.next;
//        }

        ListNode reverseTwo = solution.reverseTwo(listNode1);
        while (reverseTwo != null){
            System.out.print(reverseTwo.val + " ");
            reverseTwo = reverseTwo.next;
        }
    }
}
