package leetcode19;

import share.ListNode;


public class Main {
    public static void main(String[] args) {
        ListNode l1 = new ListNode(1);
        Solution solution = new Solution();
        System.out.println(solution.removeNthFromEnd(l1,1).val);
    }
}
