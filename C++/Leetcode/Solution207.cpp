#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
private:
    vector<vector<int>> edges; // 构造图
    vector<bool> visited; // 该节点已遍历
    vector<bool> onPath; // 
    bool valid = true; // prerequisites 为空，可完成选修课程任务
public:
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        // 构造有向图
        edges.resize(numCourses);
        visited.resize(numCourses);
        onPath.resize(numCourses);
        for (vector<int>& edge : prerequisites) {
            edges[edge[1]].push_back(edge[0]);
        }

        // 遍历图
        for (int i = 0; i < numCourses; i++) {
            dfs(i);
        }
        return valid;
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
        onPath[u] = false;
    }
};

int main() {
    vector<vector<int>> prerequisites = {{0,1},{2,1},{1,3},{3,2}};
    vector<vector<int>> a = {{0,10},{3,18},{5,5},{6,11},{11,14},{13,1},{15,1},{17,4}};
    vector<vector<int>> b = {{1,0}};
    Solution s = Solution();
    cout<<s.canFinish(2, b)<<endl;
    cout<<s.canFinish(20, a)<<endl;


}