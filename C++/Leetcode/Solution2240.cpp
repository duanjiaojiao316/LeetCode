class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        
        int n = total / cost1;
        if (n == 0) {
            return total / cost2 + 1;
        }
        long long ans = 0;
        // 购买i个cost1的钢笔
        for (int i = 0; i <= n; i++) {
            int remainder = total - cost1 * i;
            int count = remainder / cost2;  // 可以购买多少个cost2的铅笔
            ans += count + 1;
        }
        return ans;
    }
};

int main () {
    Solution s = Solution();
    s.waysToBuyPensPencils(9, 99, 7);
    return 0;
}