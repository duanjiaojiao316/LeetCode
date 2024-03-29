#include <vector>
#include <algorithm>
using namespace std;

/**动态规划*/
class Solution {
public:
    vector<int> memo;
    int jump(vector<int>& nums) {

        int n = nums.size();
        memo = vector<int>(n, n);
        return dp(nums, 0);
    }

    int dp(vector<int>& nums, int p) {
        int n = nums.size();
        if (p >= n - 1) {
            return 0;
        }
        if (memo[p] != n) {
            return memo[p];
        }
        int steps = nums[p];
        for (int i = 1; i <= steps; i++) {
            int subProblem = dp(nums, p + i);
            memo[p] = min(memo[p], subProblem + 1);
        }
        return memo[p];
    }
};

int main() {
    vector<int> arr = vector<int>{2, 3, 1, 1, 4};
    Solution s = Solution();
    s.jump(arr);
    
}
/**
 * 贪心
*/
class Solution1 {
    int jump(vector<int>& nums) {
        int n = nums.size();
        int end = 0, farthest = 0;
        int jumps = 0;
        for (int i = 0; i < n - 1; i++) {
            farthest = max(nums[i] + i, farthest);
            if (end == i) {
                jumps++;
                end = farthest;
            }
        }
        return jumps;
    }
};