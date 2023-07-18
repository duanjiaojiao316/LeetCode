#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> track;
        backtrack(nums, track);
        return res;
    }
    void backtrack(vector<int>& nums, vector<int> track) {
        if (track.size() == nums.size()) {
            res.push_back(track);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (count(track.begin(), track.end(), nums[i]) == 1) {
                continue;
            }
            track.push_back(nums[i]);
            backtrack(nums, track);
            track.pop_back();
        }
    }
};

int main() {
    vector<int> arr = {1, 2, 3,4 };
    Solution s = Solution();
    s.permute(arr);
    cout<<endl;
}