#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int farthest = 0;
        for (int i = 0; i < n - 1; i++) {
            // 不断计算能跳到的最远距离
            farthest = max(farthest, nums[i] + i);
            // 可能碰到0卡住了
            if (farthest <= i) return false;
        }
        return farthest >= n - 1;

    }
};

int main() {
    Solution s = Solution();
    vector<int> arr = {2,3,1,1,4};
    s.canJump(arr);
    return 0;
}