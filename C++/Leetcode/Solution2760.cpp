#include <vector>
using namespace std;

class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int left = 0;
        int right = left;
        int res = 0;
        while (left != nums.size()) {
            if (nums[left] % 2 != 0) {
                continue;
            } else {
                res++;
                
                for (int i = 1; i < nums.size(); i++) {
                    right = left + i;
                    if (nums[right - 1] % 2 != nums[right]) {
                        continue;
                    } else {
                        left += 2;
                        left = right;
                        break;
                    }
                }
            }

        }
    }
};