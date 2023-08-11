#include <vector>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp = vector<int>(n); // dp[i] 表示以i结尾的最大和
        dp[0] = nums[0];
        int res = dp[0];
        for (int i = 1; i < n; i++) {
            if (dp[i - 1] > 0) {
                dp[i] = dp[i - 1] + nums[i];
            } else {
                dp[i] = nums[i];
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int dp_0 = 0, dp_1;
        int res = dp_0;
        for (int i = 1; i < n; i++) {
            if (dp_0 > 0) {
                dp_1 = dp_0 + nums[i];
            } else {
                dp_1 = nums[i];
            }
            dp_0 = dp_1;
            res = max(res, dp_1);
        }
        return res;
    }
};