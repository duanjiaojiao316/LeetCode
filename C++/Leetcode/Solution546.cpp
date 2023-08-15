#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<vector<int>>> dp;
    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();
        dp = vector<vector<vector<int>>>(n, vector<vector<int>>(n,vector<int>(n)));
        return caculate(boxes, 0, n - 1, 0);
    }

    int caculate(vector<int> & boxes, int left, int right, int k) {
        if (left > right) {
            return 0;
        }

        if (dp[left][right][k] == 0) {
            // 策略1：直接将right位置的颜色和之后的相同的K个颜色消除
            dp[left][right][k] = caculate(boxes, left, right - 1, 0) + (k + 1) * (k + 1);
            // 策略2：将[left，right)中和right位置颜色相同的重叠在一起再消除，也就是将中间全部的杂色全部消除
            for (int i = left; i < right; i++) {
                if (boxes[i] == boxes[right]) {
                    dp[left][right][k] = max (dp[left][right][k], caculate(boxes, left, i, k + 1) + caculate(boxes, i + 1,right - 1, 0));
                }
            }
        }   
        return dp[left][right][k];
    }
};

int main () {
    vector<int> boxes = {6,3,6,5,6,7,6,6,8,6};
    Solution s = Solution();
    cout<<s.removeBoxes(boxes);
    return 0;
}