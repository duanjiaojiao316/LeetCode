#include <vector>
#include <string>
#include <map>
using namespace std;


/* 输入: s = "cbaebabacd", p = "abc"
输出: [0,6]
解释:
起始索引等于 0 的子串是 "cba", 它是 "abc" 的异位词。
起始索引等于 6 的子串是 "bac", 它是 "abc" 的异位词。 */

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        // unordered_map<char, int> need, window;
        map<char, int> need, window;
        vector<int> res = vector<int>(0);
        for (char c : p) need[c]++;
        int left = 0, right = 0;
        int valid = 0;

        while (right < s.size()) {
            char c = s[right];
            right++;
            if (need.count(c)) {
                window[c]++;
                if (need[c] == window[c]) {
                    valid++;
                }
            }
            while (right - left >= p.size()) {
                if (valid == need.size()) {
                    res.push_back(left);
                }
                char d = s[left];
                left++;
                if (need.count(d)) {
                    if (need[d] == window[d]) {
                        valid--;
                    }
                    window[d]--;
                }
            }

        }
        return res;
    }
};

int main() {
    Solution ss = Solution();
    string s = "cbaebabacd";
    string p = "abc";
    ss.findAnagrams(s, p);
    return 0;
}