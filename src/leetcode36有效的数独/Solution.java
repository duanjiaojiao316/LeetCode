package leetcode36有效的数独;

public class Solution {
    public boolean isValidSudoku(char[][] board) {

        for (int i = 0; i < 9; i++) {
            int rows = 0, cols = 0, box = 0;
            for (int j = 0; j < 9; j++) {
                // 由于传入为char，需要转换为int，减48
                int r = board[i][j] - 48;
                int c = board[j][i] - 48;
                int b = board[3 * (i / 3) + j / 3][3 * (i % 3) + j % 3] - 48;
                // "."的ASCII码为46，故小于0代表着当前符号位"."，不用讨论
                if(r > 0){
                    rows = sodokuer(r, rows);
                }
                if(c > 0){
                    cols = sodokuer(c, cols);
                }
                if(b > 0){
                    box = sodokuer(b, box);
                }
                if(rows == -1 || cols == -1 || box == -1){
                    return false;
                }
            }
        }
        return true;
    }

    private int sodokuer(int n, int val) {
        return ((val >> n) & 1) == 1 ? -1 : val ^ (1 << n);
    }
}
