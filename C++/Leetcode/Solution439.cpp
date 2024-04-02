#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> equit;
        vector<int> res;
        int m = nums1.size();
        int n = nums2.size();
        for (int i = 0; i < m; i++) {
            equit.emplace(nums1[i]);
        }
        for (int i = 0; i < n; i++) {
            if (equit.count(nums2[i])) {
                equit.erase(nums2[i]);
                res.emplace_back(nums2[i]);
            }
        }
        return res;
    }
};