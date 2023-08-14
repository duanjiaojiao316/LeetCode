#include <vector>
using namespace std;

// 暴力查询， 容易超出时间限制
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        int n = heights.size();

        for (int i = 0; i < n; i++) {
            int height = heights[i];
            res = max(res, height);
            for (int k = i - 1; k >= 0; k--) {
                height = min(height, heights[k]);
                res = max (res, (i - k + 1) * height);
            }
        }
        return res;

    }
};

int main() {
    Solution s = Solution();
    vector<int> heights = {2,1,5,6,2,3};
    s.largestRectangleArea(heights);
    return 0;
}

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        int n = heights.size();

        for (int i = 0; i < n; i++) {
            int height = heights[i];
            res = max(res, height);
            for (int k = i - 1; k >= 0; k--) {
                height = min(height, heights[k]);
                res = max (res, (i - k + 1) * height);
            }
        }
        return res;

    }
};