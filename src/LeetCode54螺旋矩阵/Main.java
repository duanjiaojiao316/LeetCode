package LeetCode54螺旋矩阵;

import java.util.List;

/**
 * @author duanjiaojiao
 * @create 2021/6/19 21:43
 * @description
 */
public class Main {
    public static void main(String[] args) {
        Solution solution = new Solution();
        int[][] matrix1 = {
                {1, 2, 3, 4},
                {5, 6, 7, 8},
                {9, 10, 11, 12}
        };
        List<Integer> integers1 = solution.spiralOrder(matrix1);
        System.out.println(integers1.toString());

        int[][] matrix2 = {
                {1, 2, 3},
                {4, 5, 6},
                {7, 8, 9},
                {10, 11, 12},
                {13, 14, 15}
        };
        List<Integer> integers2 = solution.spiralOrder(matrix2);
        System.out.println(integers2.toString());

        int[][] matrix3 = {
                {1, 2, 3, 4, 5},
                {6, 7, 8, 9, 10},
                {11, 12, 13, 14, 15},
                {16, 17, 18, 19, 20}
        };
        List<Integer> integers3 = solution.spiralOrder(matrix3);
        System.out.println(integers3.toString());
        int[][] matrix4 = {
                {1, 2},
                {3, 4},
                {5, 6}
        };
        List<Integer> integers4 = solution.spiralOrder(matrix4);
        System.out.println(integers4.toString());
    }
}
