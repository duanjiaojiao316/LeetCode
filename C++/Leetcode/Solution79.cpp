#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<bool>> onPath;
    int m, n;
    vector<vector<int>> directs = {{-1,0},{0,-1},{1,0},{0,1}};
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        onPath = vector<vector<bool>>(m,vector<bool>(n));
        int cur = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(board, word, i, j, cur)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool dfs (vector<vector<char>>& board, string word, int i, int j, int cur) {

        if (cur == word.size()) {
            return true;
        }
        
        if (i < 0 || i >=m || j < 0 || j >=n || onPath[i][j] || board[i][j] != word[cur]) {
            return false;
        }
            
        onPath[i][j] = true;
        for (vector<int> direct : directs) {
            int nextI = i + direct[0];
            int nextJ = j + direct[1];
            if (dfs(board, word, nextI, nextJ, cur + 1)) {
                return true;
            }
            
        }
        onPath[i][j] = false;
        return false;
    }
};

int main () {
    Solution s = Solution();

    /**
     * ABCE
     * SFCS
     * ADEE
    */
    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string word = "ABCCED";
    vector<vector<char>> board1 = {{'A','A','A','A','A','A'},{'A','A','A','A','A','A'},{'A','A','A','A','A','A'},{'A','A','A','A','A','A'},{'A','A','A','A','A','A'},{'A','A','A','A','A','A'}};
    string word1 = "AAAAAAAAAAAAAAB";
    cout<< s.exist(board, word);
    cout<< s.exist(board1, word1);
}