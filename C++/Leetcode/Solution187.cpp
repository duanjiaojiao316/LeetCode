#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.size();
        set<string> seen;
        set<string> res;
        for(int i = 0; i + 10 <= n; i++) {
            string sub_str = s.substr(i, 10);

            if (seen.count(sub_str)) {
                res.insert(sub_str);
            } else {
                seen.insert(sub_str);
            }
        }
        return vector<string>(res.begin(), res.end());
    }
};

class Solution {
public:

    vector<string> findRepeatedDnaSequences(string s) {
        // 将字符串转化为四进制的数字数组
        vector<int> nums(s.length());
        for (int i = 0; i < nums.size(); i++) {
            switch (s[i])
            {
            case 'A':
                nums[i] = 0;
                break;
            case 'G':
                nums[i] = 1;
                break;
            case 'C':
                nums[i] = 2;
                break;
            case 'T':
                nums[i] = 3;
                break;
            }
        }
        // 记录重复出现的哈希值
        set<int> seen;
        // 记录重复出现的字符串
        set<string> res;
        // 数字位数
        int L = 10;
        // 进制
        int R = 4;

        int RL = pow(R, L - 1);
        // 维护滑动窗口中字符串的哈希值
        int windowHash = 0;

        int left = 0, right = 0;

        while (right < nums.size()) {
            windowHash = windowHash * R + nums[right];
            right++;
            while (right - left == L) {
                if (seen.count(windowHash)) {
                    res.insert(s.substr(left, L));
                } else {
                    seen.insert(windowHash);
                }
                windowHash = windowHash - nums[left] * RL;
                left++;
            }
        }
        return vector<string> (res.begin(), res.end());
        
    }
};