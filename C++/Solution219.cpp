#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int left = 0, right = 0;
        set<int> s;
        while (right < nums.size()) {
            if (s.count(nums[right])) {
                return true;
            }
            s.emplace(nums[right]);
            right++;
            while(right - left > k) {
                s.erase(nums[left]);
                left++;
            }
        }
        return false;
    }
};

int main () {
    Solution s = Solution();
    vector<int> nums = vector<int>{1,2,3,1};
    s.containsNearbyDuplicate(nums, 3);
    return 0;
}