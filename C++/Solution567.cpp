#include <string>
#include <map>
#include <iostream>
using namespace std;

/**
 * 固定滑动窗口大小
*/
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        if (n2 < n1) {
            return false;
        }
        map<char, int> cnt1, cnt2;
        for (char c : s1) {
            cnt1[c]++;
        }
        for (int i = 0; i < n1; i++) {
            cnt2[s2[i]]++;
        }

        if (cnt1 == cnt2) {
            return true;
        }

        for (int i = n1; i < n2; i++) {
            cnt2[s2[i-n1]]--;
            if (cnt2[s2[i-n1]] == 0) {
                cnt2.erase(s2[i-n1]);
            }
            cnt2[s2[i]]++;

            if (cnt1 == cnt2) {
                return true;
            }

        }
        return false;
    }
};

int main() {
    Solution s = Solution();
    string s1 = "ab";
    string s2 = "eidbaooo";
    //cout << s.checkInclusion(s1,s2);

}

class Solution {
    bool checkInclusion1(string t, string s) {
        map<char, int> need, window;
        for (char c : t) need[c]++; // 将匹配字符串 填入need
        int left = 0, right = 0;
        int valid = 0; // 表示need和window匹配的字符种类数（包含字符）
        while (right < s.size()) {
            char c = s[right];
            right++;
            if (need.count(c)) {
                window[c]++;
                if (window[c] == need[c]){
                    valid++;
                }
            }
            while (right - left >= t.size()) { // 当左右指针包含的字符长度超过t字符串的长度
                if (valid == need.size()) {
                    return true;
                }
                char d = s[left];
                left++;
                if (need.count(d)) {
                    if(window[d] == need[d]) {
                        valid--;
                    }
                    window[d]--;
                }
            }
        }
        return false;
    }
    
};

