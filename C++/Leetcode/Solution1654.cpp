#include <vector>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> dp; //dp[i]记录跳到该位置的最短条数
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        // 本体难点在 怎么定义跳蚤所能跳的索引上限
        // 当 a == b，上限 x
        // 当 a > b, 上限 x + b
        // 当 a < b, 上限 max(max(forbidden) + a + b, x) + b
        int max_f = *max_element(forbidden.begin(), forbidden.end()); // 记录forbidden的最大数值
        dp.resize(max(max_f + a + b, x) + b); // x + b是条找所能跳到的最远的位置，因为它不能连续后跳两次
        set<int> forbidden_set(forbidden.begin(), forbidden.end());

        queue<tuple<int, int, int>> q;



    }
};