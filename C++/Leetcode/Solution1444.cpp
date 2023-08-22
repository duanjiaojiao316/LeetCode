#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int ways(vector<string>& pizza, int k) {
        int rows = pizza.size();
        int cols = pizza[0].size();
        long long mod = 1e9 + 7;

        // apple[i][j] 表示右下矩形中苹果的数量
        vector<vector<int>> apples(rows + 1, vector<int>(cols + 1));
        
        vector<vector<vector<int>>> dp(k+1, vector<vector<int>>(rows + 1, vector<int>(cols + 1)));
        for (int i = rows - 1; i >= 0; i--) {
            for (int j = cols - 1; j >= 0; j--) {
                apples[i][j] = apples[i][j+1] + apples[i+1][j] - apples[i+1][j+1] + (pizza[i][j] == 'A');
                dp[1][i][j] = apples[i][j] > 0;
            }
        }

        for (int ki = 2; ki <= k; ki++) {
            for(int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    // 水平切分
                    for (int i2 = i + 1; i2 < rows; i2++) {
                        if (apples[i][j] > apples[i2][j]) {
                            dp[ki][i][j] = (dp[ki][i][j] + dp[ki - 1][i2][j]) % mod;
                        }
                    }
                    // 垂直切分
                    for (int j2= j + 1; j2 < cols; j2++) {
                        if (apples[i][j] > apples[i][j2]) {
                            dp[ki][i][j] = (dp[ki][i][j] + dp[ki - 1][i][j2]) % mod;
                        }
                    }
                }
            }
        }

        return dp[k][0][0];

    }
};

int main() {
    Solution s = Solution();
    vector<string> pizza = {"A..","A..","..."};
    s.ways(pizza, 1);

    return 0;
}