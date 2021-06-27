package leetcode124求二叉树中最大路径和;


public class Solution {
    int max = Integer.MIN_VALUE;

    public int maxPathSum(TreeNode root) {
        oneSideMax(root);
        return max;
    }

    public int oneSideMax(TreeNode root) {
        if (root == null) {
            return 0;
        }
        int left = Math.max(0, oneSideMax(root.left));
        int right = Math.max(0, oneSideMax(root.right));

        max = Math.max(max ,left + right + root.val);
        return Math.max(left, right) + root.val;
    }
}
