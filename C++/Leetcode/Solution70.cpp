class Solution {
public:
    int climbStairs(int n) {
        int p = 0, q = 0, r = 1;  // 从第0级到第0级台阶 方案数为1
        for (int i = 1; i <= n; ++i) { // 从第1级开始计算
            p = q; 
            q = r; 
            r = p + q;
        }
        return r;
    }
};