#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int slow = 0, fast = 0;
        while(slow < nums.size() && nums[slow] != 0) {
            slow++;
            fast++;
        }
            
        while (fast < nums.size()) {
            if(nums[fast] != 0) {
                nums[slow] = nums[fast];
                nums[fast] = 0;
                slow++;
                fast++;
            } else {
                fast++;
            }
        }
    }
};

int main() {
    vector<int> nums = {1};
    Solution s = Solution();
    s.moveZeroes(nums);
    for (auto i: nums) {
        cout << i <<" ";
    }
    return 0;
}