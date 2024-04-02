#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        int same = 10;
        unordered_set<int> nums1_set(nums1.begin(), nums1.end());
        for (int num : nums2) {
            if (nums1_set.count(num)) {
                same = min(same, num);
            }
        }

        if (same != 10) {
            return same;
        }
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int min_1 = nums1[0];
        int min_2 = nums2[0];
        return min(min_1 * 10 + min_2, min_2 * 10 + min_1);
    }
};