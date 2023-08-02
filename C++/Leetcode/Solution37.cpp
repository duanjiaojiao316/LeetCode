#include <vector>
using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        backtrack(board, 0, 0);
    }

    bool backtrack(vector<vector<char>>& board, int i, int j) {
        int m = 9, n = 9;
        if (j == n) {
            return backtrack(board, i+1, 0);
        }
        if (i == m) {
            // 找到一个可行解，触发 base case
            return true;
        }

        // 该位置不是.,跳过
        if (board[i][j] != '.') {
            return backtrack(board, i, j + 1);
        }

        for (char ch = '1'; ch <= '9'; ch++) {
            if (!isValid(board, i, j, ch))
                continue;
            // 做选择
            board[i][j] = ch;
            // 继续穷举下一个
            // 如果找到一个可行解，立即结束
            if (backtrack(board, i, j + 1)) {
                return true;
            }
            // 撤销选择
            board[i][j] = '.';
        }
        return false;

    }

    bool isValid(vector<vector<char>>& board, int i, int j, char ch) {
        for (int x = 0; x < 9; x++) {
            if (board[i][x] == ch) {
                return false;
            }
            if (board[x][j] == ch) {
                return false;
            }

            if (board[(i/3)*3 + x/3][(j/3)*3 + x%3] == ch) {
                return false;
            }
        }
        return true;
    }
};

