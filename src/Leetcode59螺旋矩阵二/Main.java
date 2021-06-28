package Leetcode59螺旋矩阵二;

/**
 * @author duanjiaojiao
 * @create 2021/6/20 16:14
 * @description
 */
public class Main {
    public static void main(String[] args) {
        Solution solution = new Solution();
        int[][] m1 = solution.generateMatrix(1);
        int[][] m2 = solution.generateMatrix(2);
        int[][] m3 = solution.generateMatrix(3);
        int[][] m6 = solution.generateMatrix(6);
        getArrayString(m6);
        int i = 0;
    }

    public static void getArrayString(int [][] array){
        int cols = array[0].length;
        int rows = array.length;
        for (int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++) {
                System.out.print(array[i][j] + " ");
            }
            System.out.println();
        }

    }
}
