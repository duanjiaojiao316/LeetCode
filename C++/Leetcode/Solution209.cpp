#include <vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int res = nums.size() + 1;
        int left = 0, right = 0;
        int sum = 0;

        while (right < nums.size()) {
            sum += nums[right];
            right++;
            while (sum >= target) {
                int tmp = nums[left];
                
                if(sum - tmp < target) {
                    res = min(right - left, res);
                }
                left++;
                sum -= tmp;
            }
        }
        return  res==nums.size() ? 0 : res;
    }
};

int main() {

}

