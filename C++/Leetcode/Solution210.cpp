#include <vector>
#include <algorithm>
using namespace std;

class Solution {

private:
    vector<vector<int>> edges; // 构造图
    vector<bool> visited; // 该节点已遍历
    vector<bool> onPath; // 
    bool valid = true; // prerequisites 为空，可完成选修课程任务
    vector<int> courseOrders;

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        visited.resize(numCourses);
        onPath.resize(numCourses);
        // 构造有向图
        for (vector<int>& edge : prerequisites) {
            edges[edge[1]].push_back(edge[0]);
        }

        // 遍历图
        for (int i = 0; i < numCourses; i++) {
            dfs(i);
        }
        if (valid) {
            reverse(courseOrders.begin(), courseOrders.end());
            return courseOrders;
        } 
        return vector<int>{};

    }

    void dfs(int u) {
        if (onPath[u]) {
            valid = false;
        }

        if (visited[u] || !valid) {
            return;
        }
        visited[u] = true;

        onPath[u] = true;

        for (int v : edges[u]){
            dfs(v);
        }
        courseOrders.push_back(u);
        onPath[u] = false;
    }
};