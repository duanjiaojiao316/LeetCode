#include <vector>
using namespace std;

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int res = nums.size() + 1;
        int sum = 0;
        int left = 0, right = 0;
        while (right < nums.size()) {
            sum += nums[right];
            
            while (sum >= k) {
                res = min(right - left + 1 , res);
                sum -= nums[left];
                left++;
            }
            right++;
            
        }
        return res == nums.size() + 1 ? -1: res;
    }
};

int main () {
    vector<int> nums{84,-37,32,40,95};
    Solution s = Solution();
    s.shortestSubarray(nums, 167);
    return 0;
}