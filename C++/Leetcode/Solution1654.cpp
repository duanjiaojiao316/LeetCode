#include <vector>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;

// bfs
#include <unordered_set>
class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        queue<tuple<int,int,int>> q;
        unordered_set<int> visited; //标记可以达到的点
        q.emplace(0, 1, 0); // 到达位置0需要步数为0，方向1前经
        visited.emplace(0); // 添加0为可到达的点
        // 定义左右边界
        int lower = 0;
        int upper = max(*max_element(forbidden.begin(), forbidden.end()) + a, x) +b;
        // 克隆禁止区域的点到set，便于查找
        unordered_set<int> forbidden_set(forbidden.begin(), forbidden.end());

        while (!q.empty()) {
            tuple<int, int, int> tu = q.front();
            int position = get<0>(tu), direction = get<1>(tu), step = get<2>(tu);
            q.pop();
            if (position == x) {
                return step;
            }
            // 两个方向
            // 方向前进 或者 右移
            int nextPosition = position + a;
            int nextDirection = 1;
            if (lower <= nextPosition && nextPosition <= upper) {
                if (!visited.count(nextPosition * nextDirection) && !forbidden_set.count(nextPosition)) {
                    // 标记可以到达的点
                    visited.emplace(nextPosition * nextDirection);
                    // 队列中加入前进后到达的点
                    q.emplace(nextPosition, nextDirection, step + 1);
                }
            }
            // 上一次方向前进或者右移 这次左移
            if (direction == 1) {
                nextPosition = position - b;
                nextDirection = -1;
                if (lower <= nextPosition && nextPosition <= upper) {
                    if (!visited.count(nextPosition * nextDirection) && !forbidden_set.count(nextPosition)){
                        visited.emplace(nextPosition * nextDirection);
                        q.emplace(nextPosition, nextDirection, step + 1);
                    }
                }
            }
        }
        return -1;
    }
};