#include <vector>
using namespace std;

class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        vector<bool> visited(n, false);
        int i = 0;
        int times = 1;
        while (!visited[i]) {
            visited[i] = true;
            i = (i + times * k) % n; // 把球传给下一个小朋友
            times++;
        }

        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                res.push_back(i+1);
            }
        }
        return res;
    }
};

int main() {
    Solution s = Solution();
    s.circularGameLosers(5,2);
    return 0;
}