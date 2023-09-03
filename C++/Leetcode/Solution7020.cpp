#include <math.h>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int i = to_string(low / 10).size(); // 计算开始的位数

        if (i % 2 == 0) {
            i--;
        }
        if (low / 10 == 0) {
            i = -1;
        }
        
        int res = 0;

        for (int num = low; low <= num && num <= high; num++) {
            string str = to_string(num);
            int size = str.size();
            if (size % 2 == 1) {
                i += 2;
                num = pow(10, i);
                continue;
            }

            int low_sum = 0;
            int high_sum = 0;
            int num_tmp = num;
            // 计算低n位的和
            int n = size / 2;
            for (int x = 0; x < n; x++) {
                low_sum += num_tmp % 10;
                num_tmp = num_tmp / 10;
            }
            // 计算高n位的和
            for (int x = 0; x < n; x++) {
                high_sum += num_tmp % 10;
                num_tmp = num_tmp / 10;
            }
            if (low_sum == high_sum) {
                res++;
            }
        }
        return res;
    }
};

int main() {
    Solution s = Solution();
    s.countSymmetricIntegers(1, 5555);
    return 0;
}