#include <vector>
#include <queue>
using namespace std;
class Solution
{
public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<vector<int>> reverse_graph(n); // 反向图
        vector<int> inDeg(n);                 // 反向图中各个节点的入度(也就是原图中各个节点的出度)
        queue<int> terminal_nodes;            // 记录终端节点的队列
        for (int i = 0; i < n; i++)
        {
            for (int des : graph[i])
            {
                reverse_graph[des].push_back(i); // 反转图
            }
            inDeg[i] = graph[i].size();
            if (inDeg[i] == 0) // 反向图中入度为0 为终端节点
            {
                terminal_nodes.push(i); // 终端节点加入队列
            }
        }

        while (!terminal_nodes.empty())
        {
            int terminal = terminal_nodes.front();
            terminal_nodes.pop();
            for (int des : reverse_graph[terminal])
            {
                inDeg[des]--;
                if (inDeg[des] == 0) // 如果该节点的所有途径都达到终端节点，该节点为安全节点入队列，继续检测更深层次的安全节点
                {
                    terminal_nodes.push(des);
                }
            }
        }
        vector<int> ans;

        for (int i = 0; i < n; i++)
        {
            if (inDeg[i] == 0)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};