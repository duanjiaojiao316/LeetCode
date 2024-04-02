#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) {
            return false;
        }

        int sum = accumulate(nums.begin(), nums.end(), 0); 
        int maxNum = *max_element(nums.begin(),nums.end());
        if (sum % 2 == 1) {
            return false;
        }
        int target = sum / 2;
        if (maxNum > target) {
            return false;
        }

        vector<int> dp(target + 1, 0);
        dp[0] = true;

        for (int i = 1; i < n; i++) {
            int num = nums[i];
            for (int sum = target; sum >= num; sum--) {
                dp[sum] |= dp[sum - num];
            }
        }
        return dp[target];
    }
};