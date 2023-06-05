#include <string>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        string res = "";

        for (int i = 0 ; i < s.size(); i ++) {
            string s1 = palindrome(s, i, i);
            string s2 = palindrome(s, i, i + 1);
            res = res.length() > s1.length() ? res : s1;
            res = res.length() > s2.length() ? res : s2;
        }

        return res;
    }

    // 在 s 中寻找以 s[l] 和 s[r] 为中心的最长回文串
    string palindrome(string s, int l, int r) {
    // 防止索引越界
        while (l >= 0 && r < s.length()
            && s[l] == s[r]) {
            // 双指针，向两边展开
            l--; r++;
        }
    // 返回以 s[l] 和 s[r] 为中心的最长回文串
        return s.substr(l + 1, r - l - 1);
    }   
};
