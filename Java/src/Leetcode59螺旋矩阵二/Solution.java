package Leetcode59螺旋矩阵二;

/**
 * @author duanjiaojiao
 * @create 2021/6/20 16:02
 * @description
 */
public class Solution {
    public int[][] generateMatrix(int n) {
        if (n <= 0) {
            return null;
        }
        int left = 0;
        int right = n - 1;
        int top = 0;
        int bottom = n - 1;
        int target = n * n;
        int num = 1;
        int[][] matrix = new int[n][n];
        while (num <= target) {
            for (int i = left; i <= right; i++) {
                matrix[top][i] = num++;
            }
            top++;
            for (int i = top; i <= bottom; i++) {
                matrix[i][right] = num++;
            }
            right--;
            for (int i = right; i >= left; i--) {
                matrix[bottom][i] = num++;
            }
            bottom--;
            for (int i = bottom; i >= top; i--) {
                matrix[i][left] = num++;
            }
            left++;
        }
        return matrix;
    }
}
