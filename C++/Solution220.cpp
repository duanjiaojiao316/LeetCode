#include <vector>
#include <set>
using namespace std;
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        int left = 0, right = 0;
        set <int> s;
        while (right < nums.size()) {
            auto iter = s.lower_bound(nums[right] - valueDiff);
            if (iter != s.end() && *iter <= nums[right] + valueDiff) {
                    return true;
            }
            s.insert(nums[right]);
            while (right - left >= indexDiff) {
                s.erase(nums[left]);
                left++;
            }
            right++;
        }
        return false;
    }
};

int main() {
    Solution s = Solution();
    vector<int> nums = vector<int>({1,2,3,1});
    s.containsNearbyAlmostDuplicate(nums, 3, 0);
    return 0;
}

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        int left = 0, right = 0;
        set <int> s;

        for (int right = 0; right < nums.size(); right++){
            auto iter = s.lower_bound(nums[right] - valueDiff);
            if (iter != s.end() && *iter <= nums[right] + valueDiff) {
                    return true;
            }
            s.insert(nums[right]);
            if (right >= indexDiff) {
                s.erase(nums[right-indexDiff]); left++;
            }
        }
        return false;
    }
};