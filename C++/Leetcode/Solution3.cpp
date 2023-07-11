#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_length = 0;

        std::vector<char> substring = vector<char>(0);

        int i = 0;
        while (i < s.size()) {
            if (std::count(substring.begin(), substring.end(), s[i])) {
                max_length = max(max_length, (int)substring.size());
                substring.erase(substring.begin());
            } else {
                substring.push_back(s[i]);
                i++;
            }
        }
        max_length = max(max_length, (int)substring.size());
        return max_length;
    }
};

int main() {
    Solution s = Solution();
    s.lengthOfLongestSubstring("abcabcbb");
    return 0;
}

#include <map>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        int left = 0, right = 0;
        map<char, int> window;
        while (right < s.size()) {
            char c = s[right];
            right++;
            window[c]++;

            while (window[c] > 1) {
                
                char d = s[left];
                left++;
                window[d]--;
            }
            res = max(res, right-left);
        }
    }
};