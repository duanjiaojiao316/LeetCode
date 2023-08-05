#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        vector<int> path; // 过程中的路径
        traverse(graph, 0, path);
        return res;
    }

    void traverse(vector<vector<int>>& graph, int s, vector<int>& path) {
        path.push_back(s); // 添加节点到路径
        int n = graph.size();
        if (s == n - 1) { // 遇到终点
            res.push_back(path);
            path.pop_back();
            return;
        }

        for (int next : graph[s]) {
            traverse(graph, next, path);
        }
        path.pop_back();
    }
};

int main () {
    vector<vector<int>>graph = {{1,2},{3},{3},{}};
    Solution s = Solution();
    s.allPathsSourceTarget(graph);
}