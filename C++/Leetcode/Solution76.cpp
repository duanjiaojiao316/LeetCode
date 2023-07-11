#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        map <char, int> need, window;
        for (char c : t) {
            need[c]++;
        }

        int left = 0, right = 0;
        int valid = 0;
        int start = 0, len = INT_MAX;
        while (right < s.size()) {
            char c = s[right];
            right++;

            if (need.count(c)) {
                window[c]++;
                if(window[c] == need[c]) {
                    valid++;
                }
            }

            while(valid == need.size()) {
                // 更新最小覆盖字串 
                if(right - left < len) {
                    start = left;
                    len = right - left;
                }
                // d 将移除窗口
                char d = s[left];
                left++;

                if(need.count(d)) {
                    if(window[d] == need[d]){
                        valid--; 
                    }
                    window[d]--;
                }
            }
        }
        return len == INT_MAX ? "" : s.substr(start, len);
    }
};