#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;

        int left = newInterval[0];
        int right = newInterval[1];
        bool placed = false;
        for (vector<int>& interval : intervals) {
            if (interval[1] < left) {
                // 新插入节点在该节点的右侧 无交集
                res.push_back(interval);
            } else if (interval[0] > right) {
                // 新插入节点在该节点的左侧 
                if (!placed) { // 如果还未放置新插入节点
                    res.push_back({left, right});
                    placed = true;
                }
                res.push_back(interval);
            } else {
                // 如果新插入节点与当前节点有交集，计算他们的并集，将其并集更新为新的待插入节点
                left = min(interval[0], left);
                right = max(interval[1], right);
            }
        }
        if (!placed) {
            res.push_back({left, right});
        }

        return res;
    }
};
int main() {

    return 0;
}