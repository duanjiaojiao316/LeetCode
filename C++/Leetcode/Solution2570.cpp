#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int i = 0, j = 0, len1 = nums1.size(), len2 = nums2.size();
        vector<vector<int>> res;
        while(i < len1 && j < len2) {
            if (nums1[i][0] == nums2[j][0]) {
                res.push_back({nums1[i][0], nums1[i][1] + nums2[j][1]});
                i++, j++;
            } else if (nums1[i][0] > nums2[j][0]){
                res.push_back(nums2[j]);
                j++;
            } else {
                res.push_back(nums1[i]);
                i++;
            }
        }
        if (i == len1) {
            res.insert(res.end(), nums2.begin() + j, nums2.end());
        } else if (j == len2) {
            res.insert(res.end(), nums1.begin() + i, nums1.end());
        }

        return res;
    }
};

int main() {
    Solution s = Solution();
    vector<vector<int>> nums1 = {{1,2}, {2,3}, {4,5}};
    vector<vector<int>> nums2 = {{1,4}, {3,2}, {4,1}};
    vector<vector<int>> rs = s.mergeArrays(nums1, nums2);
    return 0;
}