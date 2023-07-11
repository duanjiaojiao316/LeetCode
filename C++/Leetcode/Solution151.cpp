#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        //TODO: 1.去除多余的空格

        removeExtraSpaces(s);

        //TODO: 2.反转整个字符串
        reverse(s, 0, s.size() - 1);

        //TODO: 3.反转单个单词字符
        int start = 0;
        for (int i = 0; i < s.size() && start < s.size(); i++) {
            if (s[i] == ' ') {
                reverse(s, start, i - 1);
                start = i + 1;
            }
            if (i == s.size() - 1) {
                reverse(s, start, i);
            }
        }
        return s;
    }

    void reverse(string& s, int i, int j) {
        while (i < j) {
            swap(s[i++], s[j--]);
        }
    }

    void removeExtraSpaces(string& s) {
        int slow = 0;
        int fast = 0;

        // 去除开头位置的多余空格
        while (s[fast] == ' ') {
            fast++;
        }

        // 去除中间位置多余空格
        while (fast < s.size()) {
            if (fast > 0 && s[fast] == ' ' && s[fast - 1] == ' ') {
                fast++;
            } else {
                s[slow] = s[fast];
                slow++;
                fast++;
            }

        }

        // 去除结尾位置多余空格

        if (slow - 1 > 0 && s[slow - 1] == ' ') {
            slow--;
        }
        s.resize(slow);
    }
};
