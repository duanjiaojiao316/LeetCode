class Solution {
public:
    int minOperations(int n) {
        int step = 0;
        int cnt = 0;
        for (;n > 0; n >>= 1) {
            if (n & 1) { // 计算n二进制数的结尾连续的1的个数
                cnt++;
            } else {
                if (cnt == 1) { // 只有一个1结尾，使用减法-1
                    step++;
                    cnt = 0;
                } else if (cnt > 1) { // 结尾有大于一个1，使用加法+1 然后高位会出现一个1 再在后续的操作中减去或加上1
                    step++;
                    cnt = 1;
                }
            }
        }
        // 处理最开头的数字1
        if (cnt == 1) {
            step++;
        } else if (cnt > 1) {
            step += 2;
        }
        return step;
    }
};
int main() {
    Solution s = Solution();
    s.minOperations(39);
}

#include <math.h>
using namespace std;

class Solution1 {
public:
    int minOperations(int n) {
        int step = 0;
        while (n != 0) {
            int tmp = round(log2(n));
            n = abs(n - pow(2,tmp));
            step++;
        }
        return step;
    }
};