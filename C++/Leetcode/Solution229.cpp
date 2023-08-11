#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        int n = nums.size() / 3;
        unordered_map<int,int> counts;
        for (int& num : nums) {
            counts[num]++;
        }
        for (auto& count : counts) {
            if (count.second > n) {
                res.push_back(count.first);
            }
        }
        return res;

    }
};