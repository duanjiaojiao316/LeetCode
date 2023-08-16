#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> res; // 存储所有IP
    vector<int> temp; // 存储IP的数字段

    vector<string> restoreIpAddresses(string s) {
        backtrack(s, 0 , 4);
        return res;
    }

    void backtrack(string s, int start, int k) {
        if (k == 0 || start == s.size()) {
            if (k == 0 && start == s.size()) {
                string ip;
                for (auto str : temp) {
                    ip += to_string(str) + '.';
                }
                res.push_back(ip.substr(0, ip.size() - 1));
            }
            return;
        }
        for (int end = start; end < s.size() && end < start + 3; end++) {
            if (end > start && s[start] == '0') {
                return; // 不能有前导0
            }
            int v = stoi(s.substr(start, end - start + 1));
            if (v >= 0 && v <= 255) {
                temp.push_back(v);
                backtrack(s, end + 1, k - 1);
                temp.pop_back();
            }
        }
    }
};

int main() {
    Solution s = Solution();
    s.restoreIpAddresses("25525511135");
    return 0;
}