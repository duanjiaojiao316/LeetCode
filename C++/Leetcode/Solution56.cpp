#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        
        if (intervals.size() == 0) {
            return res;
        }

        sort(intervals.begin(),intervals.end());
        res.emplace_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            vector<int> tmp = res.back();
            if (tmp[1] >= intervals[i][0]) {
                if (tmp[1] < intervals[i][1]) {
                    tmp[1] = intervals[i][1];
                    res.pop_back();
                    res.emplace_back(tmp);
                }
            } else {
                res.emplace_back(intervals[i]);
            }
        }
        return res;
    }
};

int main() {
    vector<vector<int>> intervals = {{}};
    Solution s = Solution();
    s.merge(intervals);
    cout<<""<<endl;
}