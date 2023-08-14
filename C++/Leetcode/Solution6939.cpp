#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxSum(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> coms(10);

        for (int num : nums) {
            int bigger = 0;
            int num_pre = num;

            while (num) {
                bigger = max(num % 10, bigger);
                num = num / 10;
            }
            coms[bigger].push_back(num_pre);    
        }

        int res = -1;
        for (pair<int, vector<int>> com : coms) {
            int m = com.second.size();
            if (m < 2) {
                continue;
            }
            sort(com.second.begin(), com.second.end());
            res = max(res, com.second[m - 1] + com.second[m - 2]);

        }
        
        return res;
    }
};

int main() {
    vector<int> nums = {68,8,100,84,80,14,88};
    Solution s  = Solution();
    s.maxSum(nums);
    return 0;
}