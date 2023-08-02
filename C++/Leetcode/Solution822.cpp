#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        unordered_set<int> same;
        int res = 2001;
        int n = fronts.size();
        for (int i = 0; i < n; i++) {
            if (fronts[i] == backs[i]) {
                same.insert(fronts[i]);
            }
        }

        for (int x : fronts) {
            if (x < res && same.count(x) == 0) {
                res = x;
            }
        }

        for (int x : backs) {
            if (x < res && same.count(x) == 0) {
                res = x;
            }
        }
        return  res > 2000? 0 : res;

    }
};