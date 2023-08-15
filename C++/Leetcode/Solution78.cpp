#include <vector>
using namespace std;

class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        for (int mask = 0; mask < (1 << n); mask++) {
            path.clear();
            for (int i = 0; i < n; i++) {
                int temp = 1 << i;
                if (mask & (1<<i)) {
                    path.push_back(nums[i]);
                }
            }
            res.push_back(path);
        }
        return res;
    }
};

class Solution1{
public:
    vector<int> path;
    vector<vector<int>> res;
    vector<vector<int>> subsets(vector<int>& nums) {
        backtrack(nums, 0);
        return res;
    }
    void backtrack(vector<int>& nums, int start) {
        res.push_back(path);
        for (int i = start; i < nums.size(); i++) {
            path.push_back(nums[i]);
            backtrack(nums, i+1);
            path.pop_back();
        }

    }
};

int main() {
    Solution s = Solution();
    vector<int> nums = {1,2,9};
    s.subsets(nums);
    return 0;
}