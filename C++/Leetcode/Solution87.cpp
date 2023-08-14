#include <string>
#include <vector>
using namespace std;

class Solution1 {
public:
    bool isScramble(string s1, string s2) {
        if (s1 == s2) {
            return true;
        }
        int n = s1.size();
        int m = s1.size();
        if (n != m) { // 如果s1 s2的长度不等 表示s2不可能是s1变换而来
            return false;
        }
        // dp[i][j][len] 表示s2中从j开始长度为len的字符串是否由s1从i开始长度为len的字符串变换而来
        vector<vector<vector<bool>>> dp(n, vector<vector<bool>>(n, vector<bool>(n+1))); 
        // 初始化dp数组单个字符
        for (int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if (s1[i] == s2[j]) {
                    dp[i][j][1] = true;
                }
            }
        }
        // 初始化2 - n长度区间

        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                for (int j = 0; j <= n - len; j++) {
                    // 字符串划分位置为K
                    for (int k = 1; k < len; k++) {
                        if (dp[i][j][k] && dp[i+k][j+k][len-k]) {
                            dp[i][j][len] = true;
                            break;
                        }

                        if (dp[i][j + len - k][k] && dp[i+k][j][len - k]) {
                            dp[i][j][len] = true;
                            break;
                        }
                    }


                }
            }
        }
        return dp[0][0][n];
    }
};

#include <unordered_map>
// 递归方法
class Solution
{
public:
    bool isScramble(string s1, string s2) {
        int n = s1.size();
        int m = s1.size();
        if (n != m) { // 如果s1 s2的长度不等 表示s2不可能是s1变换而来
            return false;
        }
        if (s1 == s2) {
            return true;
        }

        // 判断字符个数是否一致
        unordered_map<char,int> map_char;

        for (int i = 0; i < n; i++) {
            map_char[s1[i]] += 1;
            map_char[s2[i]] -= 1;
        }
        for (auto & a : map_char) {
            if (a.second != 0) {
                return false;
            }
        }
        for (int i = 1; i < n; i++) {
            size_t first = 0;
            size_t second = i;

            bool flag = (isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i)))
            || (isScramble(s1.substr(0, i), s2.substr(n - i)) && isScramble(s1.substr(i), s2.substr(0, n - i)));
            if (flag) {
                return true;
            }
        }
        return false;

    }
};

int main() {
    Solution s = Solution();
    string s1 = "great";
    string s2 = "rgeat";
    s.isScramble(s1, s2);
}
