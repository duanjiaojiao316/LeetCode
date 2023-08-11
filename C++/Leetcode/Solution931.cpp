#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            dp[0][i] = matrix[0][i];
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // dp[i - 1][j - 1], dp[i - 1][j], dp[i - 1][j + 1]
                if (j - 1 >= 0 && j + 1 < n) {
                    dp[i][j] = minInThree(dp[i - 1][j - 1], dp[i - 1][j], dp[i - 1][j + 1]) + matrix[i][j];
                } else if (j == 0) {
                    dp[i][j] = min(dp[i - 1][j], dp[i - 1][j + 1]) + matrix[i][j];
                } else if (j == n - 1){
                    dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + matrix[i][j];
                }
            }
        }

        int res = INT_MAX;
        for (int i = 0; i < n; i++) {
            res = min(res, dp[n - 1][i]);
        }
        return res;

    }

    int minInThree(int a, int b, int c) {
        int res;
        res = min(a, b);
        res = min(c, res);
        return res;
    }
};

int main() {
    Solution s = Solution();
    vector<vector<int>>matrix = {{100,-42,-46,-41},{31,97,10,-10},{-58,-51,82,89},{51,81,69,-51}};
    s.minFallingPathSum(matrix);

}