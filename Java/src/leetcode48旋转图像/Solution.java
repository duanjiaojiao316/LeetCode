package leetcode48旋转图像;

/**
 * matrix[rows][cols] = matrix[cols][n-1-rows]
 * <p>
 * 步骤1：matrix[rows][cols] = matrix[n-1-rows][cols] 镜像
 * 步骤2：matrix[n-1-rows][cols] = matrix[cols][n-1-rows]
 */

public class Solution {

    public void rotate(int[][] matrix) {
        int n = matrix.length;
        // 镜像
        for (int i = 0; i < n / 2; i++) {
            for (int j = 0; j < n; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[n - 1 - i][j];
                matrix[n - 1 - i][j] = temp;
            }
        }

        // 转置

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
    }
}
