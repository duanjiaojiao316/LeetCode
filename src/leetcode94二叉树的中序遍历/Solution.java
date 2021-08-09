package leetcode94二叉树的中序遍历;

import share.TreeNode;

import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

public class Solution {

    /**
     * 递归法
     * @param root 二叉树根结点
     * @return 中序遍历顺序的数组
     */
    public List<Integer> inorderTraversal(TreeNode root){
        List<Integer> res = new ArrayList<>();
        if (root != null){
           inOrder(root, res);
        }
        return res;
    }

    public void inOrder(TreeNode node, List<Integer> res){
        if(node == null){
            return;
        }
        inOrder(node.left, res);
        res.add(node.val);
        inOrder(node.right,res);
    }

    /**
     * 迭代法
     * @param root 二叉树根结点
     * @return 中序遍历顺序的数组
     */
    public List<Integer> inorderTraversal1(TreeNode root) {
        List<Integer> res = new ArrayList<>();
        Stack<TreeNode> stack = new Stack<>();

        while(root != null || !stack.empty()){
            while(root != null){
                stack.push(root);
                root = root.left;
            }
            root = stack.pop();
            res.add(root.val);
            root = root.right;

        }
        return res;
    }


}
