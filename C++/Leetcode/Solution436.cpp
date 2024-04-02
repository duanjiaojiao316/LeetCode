#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> res(n, -1);

        vector<pair<int,int>> clone;
        for (int i = 0; i < n; i++) {
            clone.emplace_back(intervals[i][0], i);
        }
        sort(clone.begin(), clone.end());

        for (int i = 0; i < n; i++) {
            int left = 0;
            int right = n - 1;
            while (left < right) {
                int mid = (left + right) / 2;
                if (clone[mid].first >= intervals[i][1]) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }

            res[i] = clone[right].first >= intervals[i][1] ? clone[right].second : -1;
        }
        return res;
    }
};