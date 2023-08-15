#include <vector>
using namespace std;

class Solution {
public:
    vector<int> track;
    vector<vector<int>> res;
    vector<vector<int>> combine(int n, int k) {
        backtrack(n, 1, k);
        return res;

    }
    void backtrack(int n, int start, int k) {
        if (k == track.size()) {
            res.push_back(track);
            return;
        }

        for (int i = start; i <= n; i++) {
            track.push_back(i);
            backtrack(n, i + 1, k);
            track.pop_back();
        }
    }
};