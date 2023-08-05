#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<vector<int>>> res;
    int m, n, startI, startJ, blocks = 0, ans;
    

    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        // 查找开始节点的位置，以及障碍物的个数 
        for (int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    startI = i;
                    startJ = j;
                } else if (grid[i][j] == -1) {
                    blocks++;
                }
            }
        }
         
        vector<vector<int>> path; // 记录路径
        vector<vector<int>> sign = grid;

        traverse (sign, startI, startJ, path);

        return res.size();
    }

    void traverse(vector<vector<int>>& sign, int x , int y, vector<vector<int>>& path) {
        
        if (x >=0 && x < m && y >=0 && y < n && sign[x][y] >= 0) {
            // 做出决定
            path.push_back({x,y});

            if (sign[x][y] == 2 ) {
                if (path.size() == m * n - blocks) {
                    res.push_back(path);
                    path.pop_back();
                    return;
                }
                path.pop_back();
                return;
            }
            sign[x][y] = -2; // 标识这个位置已经遍历

            vector<vector<int>> dirs={{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
            for (vector<int> dir : dirs) {
                int nextX=x+dir[0];
                int nextY=y+dir[1];
                
                traverse(sign, nextX, nextY, path);
            }
            // 撤销决定
            path.pop_back();
            sign[x][y] = 0;
        }  
    }
};
#include <iostream>
int main() {
    vector<vector<int>> grid = {{1, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 2, -1}};
    vector<vector<int>> grid1 = {{1, 0, 0, 0},{0, 0, 0, 0},{0, 0, 0, 2}};
    vector<vector<int>> grid2 = {{0,1},{2,0}};
    Solution s = Solution();
    cout<<s.uniquePathsIII(grid) <<endl;  //2
    cout<<s.uniquePathsIII(grid1)<<endl; //4
    cout<<s.uniquePathsIII(grid2)<<endl; //0
    return 0;
}