#include <vector>
using namespace std;

class Solution {
public:
    
    // dp(i, j)记录将开区间 (i,j)内的位置全部填满气球能够得到的最多硬币数。
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp; 
        dp.resize(n + 2, vector<int>(n + 2));
        
        vector<int> val;
        val.push_back(1);  // val记录的数据时 1 nums[i] 1 长度为n + 2
        for (int i = 0; i < n; i++) {
            val.push_back(nums[i]);
        }
        val.push_back(1);

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 2; j <= n + 1; j++) {
                for (int mid = i + 1; mid < j; mid++) {
                    int sum = val[i] * val[mid] * val[j]; 
                    sum += dp[i][mid] + dp[mid][j];
                    dp[i][j] = max(dp[i][j], sum);
                }
            }
        }
        return dp[0][n + 1];
    }
};