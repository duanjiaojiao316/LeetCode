#include <vector>
using namespace std;

class Solution {
public:
    static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0 , -1}, {0, 1}};
    int rows, columns;
    vector<vector<int>> matrix;
    vector<vector<int>> pathLen; // 求得以（row，column）为起点的最长递增路径

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return 0;
        }
        matrix = matrix;
        rows = matrix.size();
        columns = matrix[0].size();

        pathLen.resize(rows, vector<int>(columns));
        int ans = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                ans = max(ans, dfs(i, j));
            }
        }
        return ans;
    }

    int dfs(int row, int column) {
        if (pathLen[row][column] != 0) {
            return pathLen[row][column];
        }
        int path = 1;
        for (int i = 0; i < 4; i++) {
            int x = row + dirs[i][0];
            int y = column + dirs[i][1];
            if (x < 0 || x >= rows || y < 0 || y >= columns || matrix[x][y] <= matrix[row][column]) {
                continue;
            }
            path = max(path, dfs(x, y) + 1);
        }
        pathLen[row][column] = path;
        return path;
    }
};