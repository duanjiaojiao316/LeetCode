#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int N = nums.size();
        if (N == 0) {
            return 0;
        }
        if (N == 1){
            return nums[0];
        }
        int first = nums[0];
        int second = max(nums[0],nums[1]);
        for (int i = 2; i < N; i++) {
            int tmp = second;
            second = max(second, nums[i] + first);
            first = tmp;
        }
        return second;
    }
};

int main() {
    vector<int> nums = {2,7,9,3,1};
    Solution s = Solution(); 
    s.rob(nums);
    return 0;
}