#include <vector>
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int left = 0, right = 0;
        int mul = 1;
        int res = 0;
        while (left < nums.size() && right < nums.size()) {
            mul *= nums[right];
            if (mul < k) {
                res++;
            }

            if (mul >= k || right == nums.size() - 1) {
                left++;
                right = left;
                mul = 1;
                continue;
            }
            right++;
        }
        return res;
    }
};

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int left = 0, right = 0;
        int mul = 1;
        int res = 0;
        if (k<2) return 0;
        while (right != nums.size()) {
            mul *= nums[right];

            while (mul >= k) {
                mul /= nums[left]; 
                left++;
            }
            right++;
            res += right - left;
        }
        return res;
    }
};

int main() {
    vector<int> nums{10,5,2,6};
    Solution s = Solution();
    s.numSubarrayProductLessThanK(nums, 100);
    return 0;
}