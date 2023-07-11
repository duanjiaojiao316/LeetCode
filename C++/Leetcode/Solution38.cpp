#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        vector<string> res = vector<string>(1);
        res[0] = "1";
        for (int i  = 1; i < n; i++) {
            int left = 0, right = 0;
            string pre = res[i - 1];
            string cur = "";
            int len = pre.length();
            while (right < len) {
                while (right < len && pre[left] == pre[right]) {
                    right++;
                }
                cur += to_string(right - left);
                cur += pre[left];
                left = right;
            }

            res.push_back(cur);
        }
        return res.back();
    }
};

int main() {
    Solution s = Solution();
    s.countAndSay(5);
}