#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 0) {
            return vector<int>{};
        }
        // 通过edges构建图，并找到度为1的节点
        // 度为1的节点为叶子节点
        vector<int> res;
        vector<int> degrees(n);
        vector<vector<int>> graph(n);
        for (vector<int> edge : edges) {
            int u = edge[0];
            int v = edge[1];
            degrees[u]++;
            degrees[v]++;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (degrees[i] == 1) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            res = {};
            // 第一层 叶子节点的个数
            int size = q.size();

            for (int i = 0; i < size; i++) {
                int u = q.front();
                q.pop();
                res.push_back(u);
                // u 节点的邻接节点入队列
                for (int v : graph[u]) {
                    degrees[v]--;
                    if (degrees[v] == 1) {
                        q.push(v);
                    }
                }
            }
        }
        return res;

    }
};