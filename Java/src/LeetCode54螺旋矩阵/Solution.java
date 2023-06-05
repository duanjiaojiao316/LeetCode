package LeetCode54螺旋矩阵;


import java.util.ArrayList;
import java.util.List;

/**
 * @author duanjiaojiao
 * @create 2021/6/19 21:21
 * @description
 */
public class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        if (matrix == null || matrix.length == 0 || matrix[0].length == 0) {
            return null;
        }
        List<Integer> list = new ArrayList<Integer>();
        int cols = matrix[0].length;
        int rows = matrix.length;
        // 循环遍历矩阵可以看作 回字 的遍历，每一次遍历的起点都是（i，i）
        // 遍历次数为 行数和列数中最小值除以2
        int numberOfTraverses = (Math.min(cols, rows) + 1) / 2;

        for (int i = 0; i < numberOfTraverses; i++) {
            // 从左到右
            for (int j = i; j < cols - i; j++) {
                list.add(matrix[i][j]);
            }
            // 从上到下
            for (int j = i + 1; j < rows - i; j++) {
                list.add(matrix[j][cols - 1 - i]);
            }
            // 在每一个循环层次中，要注意中间只剩下一行或者一列没有遍历，这种情况下不进行从右往左从下到上的遍历
            // i 是遍历层的左边界和上边界，cols - 1 - i是有边界 rows - 1 - i是下边界
            // 只有左边界小于有边界同时上边界小于下边界的情况下中间没有遍历的是一个回字而不是一行或者一列
            if(i < cols - 1 - i && i < rows - 1 - i) {
                // 从右到左
                for (int j = cols - 1 - i - 1; j >= i; j--) {
                    list.add(matrix[rows - 1 - i][j]);
                }
                // 从下到上
                for (int j = rows - 1 - i - 1; j > i; j--) {
                    list.add(matrix[j][i]);
                }
            }
        }
        return list;
    }
}
