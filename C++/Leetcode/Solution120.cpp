#include <vector>
using namespace std;

class Solution1 {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        if (n == 1) {
            return triangle[0][0];
        }
        vector<vector<int>> dp; // 记录到达该位置的最短路径和
        dp.push_back({triangle[0][0]});
        for (int i = 1; i < n; i++) {
            vector<int> tmp(i + 1);
            for (int j = 0; j <= i; j++) {
                if (j - 1 >= 0 && j < i) {
                    tmp[j] = min(dp[i - 1][j], dp[i - 1][j - 1]) + triangle[i][j];
                } else if (j == i){
                    tmp[j] = dp[i - 1][j - 1] + triangle[i][j];
                } else {
                    tmp[j] = dp[i - 1][j] + triangle[i][j];
                }
            }
            dp.push_back(tmp);
        }
        int res = __INT_MAX__;

        for (int i = 0; i < n; i++) {
            res = min(res, dp[n - 1][i]);
        }
        return res;
    
    }
};


class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        if (n == 1) {
            return triangle[0][0];
        }
        vector<int> dp; // 记录到达该位置的最短路径和
        dp.push_back({triangle[0][0]});
        int res = __INT_MAX__;
        for (int i = 1; i < n; i++) {
            vector<int> tmp(i + 1);
            for (int j = 0; j <= i; j++) {
                if (j - 1 >= 0 && j < i) {
                    tmp[j] = min(dp[j], dp[j - 1]) + triangle[i][j];
                } else if (j == i){
                    tmp[j] = dp[j - 1] + triangle[i][j];
                } else {
                    tmp[j] = dp[j] + triangle[i][j];
                }
                if (i == n - 1) {
                    res = min(res, tmp[j]);
                }
            }
            dp = tmp;
        }
        return res;
    
    }
};

int main () {
    vector<vector<int>> triangle = {{2},{3,4},{6,5,7},{4,1,8,3}};
    
    Solution s = Solution();
    s.minimumTotal(triangle);
    
}