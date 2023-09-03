#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<int> minutes; // 怪兽到达的分钟数
               
        for (int i = 0; i < n; i++) {
            minutes.push_back(dist[i]/ speed[i] - 1);
        }
        sort(minutes.begin(), minutes.end());
        for (int i = 0; i < n; i++) {
            if (minutes[i] <= i) {
                return i;
            }
        }
        return n;
    }
};

int main() {
    Solution s = Solution();
    vector<int> dist = {4,2,3};
    vector<int> speed = {2,1,1};
    s.eliminateMaximum(dist, speed);
    return 0;
}