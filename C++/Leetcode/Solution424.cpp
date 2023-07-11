#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> nums(26);
        int left = 0, right = 0;
        int max_char_length = 0; // 字符串中最长字符的个数
        while (right < s.length()) {
            nums[s[right] - 'A']++;
            max_char_length = max(max_char_length, nums[s[right] - 'A']);
            
            if (right - left + 1 - max_char_length > k) {
                nums[s[left] - 'A']--;
                left++;
            }
            right++;
        }
        return right - left;
    }
};