#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) {
            return n;
        }
        int left = 2, right = 2;
        while (right < n) {
            if (nums[left - 2] != nums[right]) {
                nums[left] = nums[right];
                ++left;
            }
            ++right;
        }
        return left;

    }
};

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int write = 0, scan = 0;
        while (scan < nums.size()) {
            if (write-2 >= 0 && nums[scan] == nums[write-2]) {
                scan++;
                continue;
            }
            nums[write++] = nums[scan++];
        }
        return write;
    }
};