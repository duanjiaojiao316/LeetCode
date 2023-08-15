#include <vector>
using namespace std;

class Solution1 {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        res.reserve(1<<n);
        res.push_back(0);

        for (int i = 1; i <= n; i++) {
            int m = res.size();
            for (int j = m - 1; j >= 0; j--) {
                res.push_back(res[j] | (1 << (i - 1)));
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        res.push_back(0);
        int head = 1;
        for (int i = 0; i < n; i++) {
            for (int j = res.size() - 1; j >= 0; j--) {
                res.push_back(head + res[j]);
            }
            head <<= 1;
        }
        return res;
    }
};

int main() {
    Solution s = Solution();
    s.grayCode(4);
    return 0;
}