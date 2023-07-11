package Leetcode59螺旋矩阵二;

/**
 * @author duanjiaojiao
 * @create 2021/6/20 16:14
 * @description
 */
public class Main {
    public static void main(String[] args) {

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
