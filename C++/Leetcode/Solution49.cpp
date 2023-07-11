#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp; // mp，以排序后的字符串为key，以其value存储互为异位的字符串
        for (string&str: strs) {
            string key = str;
            sort(key.begin(), key.end()); // 将字符串进行排序，互为字母异位的来个字符串排序后的字符串相同
            mp[key].emplace_back(str);
        }
        vector<vector<string>> res;
        for (auto it = mp.begin(); it!= mp.end(); it++) {
            res.emplace_back(it->second);
        }
        return res;

    }
};

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp; // mp，以长度为26字符串记录每个小写字符出现的次数的字符串为key，以其value存储互为异位的字符串
        vector<vector<string>> res;
        for (string str: strs) {
            string key = string(26, '0');
            for (auto c : str) {
                ++key[c - 'a'];
            }
            mp[key].emplace_back(str);
        }
        
        for (auto it = mp.begin(); it!= mp.end(); it++) {
            res.emplace_back(it->second);
        }
        return res;

    }
};