#include <vector>
using namespace std;
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        if (n == 1) {
            return mat[0][0];
        }
        int res = 0;

        for(int i = 0; i < n; i++) {
            res += (mat[i][i] + mat[i][n - 1 - i]);
        }
        return n % 2 == 0 ? res : res - mat[n/2][n/2];
    }
};

int main() {
    vector<vector<int>> matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    Solution s = Solution();
    s.diagonalSum(matrix);
    return 0;
}