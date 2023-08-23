#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) {
        // map 记录所有点相连的边数
        vector<int> degrees(n + 1, 0);
        // 记录 a-b两个点之间边的个数 key为a * n + b
        unordered_map <int, int> cnt;

        for(vector<int>& edge: edges) {
            int x = edge[0];
            int y = edge[1];
            degrees[x]++;
            degrees[y]++;
            if (x > y) {
                swap(x, y); // 存在重复的边 （1，2） 或者（2，1）
            }
            cnt[x * n + y]++;

        }
        int size = queries.size();
        
        
        
        unordered_map <int, int> incident;
        for (int x = 1; x <= n; x++) {
            for (int y = x + 1; y <= n; y++) {
                incident[x * 10 + y] = degrees[x] + degrees[y] - cnt[x * n + y];
            }
        }

        vector<int> answer(size, 0);
        for (int i = 0; i < size; i++) {
            for (auto& a: incident) {
                if (a.second > queries[i]) {
                    answer[i]++;
                }
            }
        }
        return answer;
    }
};

int main() {
    Solution s = Solution();
    vector<vector<int>> edges = {{1,2},{2,4},{1,3},{2,3},{2,1}};
    vector<int> queries = {2,3};
    s.countPairs(4, edges, queries);
    return 0;
}