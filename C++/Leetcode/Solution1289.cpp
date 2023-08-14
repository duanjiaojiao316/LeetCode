#include <vector>
using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 1) {
            return grid[0][0];
        }
        vector<vector<int>> dp(n, vector<int>(n));

        vector<int> mins = minAndSecondMin(grid[0]);// 求每一列的第一小和第二
        for (int i = 0; i < n; i++) {
            dp[0][i] = grid[0][i];      
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j != mins[1]) {
                    dp[i][j] = grid[i][j] + mins[0];
                } else {
                    dp[i][j] = grid[i][j] + mins[2];
                }
                
            }
            mins = minAndSecondMin(dp[i]);
        }
        return mins[0];
    }

    vector<int> minAndSecondMin(vector<int>& nums) {
        int min = nums[0], second_min = nums[1];
        int min_i = 0, second_min_i = 1;
        if (min > second_min) {
            int temp = min;
            min = second_min;
            second_min = temp;
            min_i = 1;
            second_min_i = 0;
        }

        for (int i = 2; i < nums.size(); i++) {

            if (nums[i] < min) {
                second_min = min;
                second_min_i = min_i;
                min = nums[i];
                min_i = i;
            } else if (nums[i] < second_min) {
                second_min = nums[i];
                second_min_i = i;
            }        
        }
        return vector<int>{min, min_i, second_min, second_min_i};
    }
};

int main() {
    Solution s = Solution();
    vector<vector<int>> matrix = {{100,-42,-46,-41},{31,97,10,-10},{-58,-51,82,89},{51,81,69,-51}};
    vector<vector<int>> matrix2 = {{-73,61,43,-48,-36},{3,30,27,57,10},{96,-76,84,59,-15},{5,-49,76,31,-7},{97,91,61,-46,67}};
    s.minFallingPathSum(matrix);
    return 0;
}