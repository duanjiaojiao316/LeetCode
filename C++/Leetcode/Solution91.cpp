#include <string>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if (n < 1) {
            return 0;
        }
        vector<int> dp(n + 1); 
        dp[0] = 1;
        dp[1] = s[0] == '0'? 0 : 1;
        for (int i = 2; i <= n; i++) {
            char c = s[i-1], d = s[i-2];
            if ('1' <= c && c <= '9') {
                // 1. s[i] 本身可以作为一个字母
                dp[i] += dp[i - 1];
            }
            if (d == '1' || d == '2' && c <= '6') {
                // 2. s[i] 和 s[i - 1] 结合起来表示一个字母
                dp[i] += dp[i - 2];
            }
        }
        return dp[n];
    }
};

int main() {
    Solution s = Solution();
    string str = "12";
    s.numDecodings(str);
    return 0;
}