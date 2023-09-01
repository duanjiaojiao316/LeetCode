#include <vector>
using namespace std;
class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        vector<int> degree(n);
        vector<vector<int>> graph(n, vector<int>(n)); // 图的邻接矩阵
        for (vector<int>& edge: edges) {
            int v = edge[0] - 1;
            int u = edge[1] - 1;
            degree[v]++;
            degree[u]++;
            graph[u][v] = 1;
            graph[v][u] = 1;
        }
        int ans = __INT_MAX__;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (graph[i][j] == 1) {
                    for (int k = j + 1; k < n; ++k) {
                        if (graph[i][k] == 1 && graph[j][k] == 1) {
                            ans = min(ans, degree[i] + degree[j] + degree[k] - 6);
                        }
                    }
                }
            }
        }
        return ans == __INT_MAX__? -1 : ans;
    }
};