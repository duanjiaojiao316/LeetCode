#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<string> res;

    string getPermutation(int n, int k) {
        vector<int> track;
        backtrack(n, k, track);
        return res.back();
    }
    void backtrack(int n, int k, vector<int> track) {
        if (res.size() == k) {
            return;
        }
        if (track.size() == n) {
            string tmp_track = "";
            for(int i = 0; i < track.size(); i++) {
                tmp_track += track[i] + '0';
            }
            res.push_back(tmp_track);
            return;
        }
        for (int i = 1; i <= n; i++) {
            // 判断该数字是否使用
            if (count(track.begin(), track.end(), i) == 1) {
                continue;
            }
            track.push_back(i);
            backtrack(n, k, track);
            track.pop_back();
        }
    }
};

class Solution1 {
    vector<bool> used;
    string getPermutation(int n, int k) {
        used = vector<bool>(n + 1, false);

        
    }
    /**
     * 计算每个数字 0-9的阶乘，用factorial记录
    */
    vector<int> factorial;
    int calculateFactorial(int n) {
        factorial = vector<int>(n + 1);
        factorial[0] = 1;
        for (int i = 1; i <= n; i++) {
            factorial[i] = factorial[i - 1] * i;
        }
    }
};