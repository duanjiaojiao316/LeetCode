#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> answer;
        for (int i = 0; i <= rowIndex; i++) {
            vector<int> row(i + 1);
            row[0] = 1;
            row[i] = 1;
            for (int j = 1; j < i; j++) {
                row[j] = answer[i - 1][j] + answer[i - 1][j - 1];
            }
            answer.push_back(row);
        }
        return answer[rowIndex];
    }
};

int main() {
    Solution s = Solution();
    s.getRow(5);
}