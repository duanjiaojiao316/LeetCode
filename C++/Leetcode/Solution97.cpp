#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size();
        int n2 = s2.size();
        int n3 = s3.size();

        if (n1 + n2 != n3) {
            return false;
        }
        
        auto f = vector<vector<bool>> (n1 + 1, vector<bool>(n2 + 1, false));
        f[0][0] = true;

        for (int i = 0; i <= n1; i++) {
            for (int j = 0; j <= n2; j++) {
                int p = i + j - 1;
                if (i > 0) {
                    f[i][j] = f[i][j] || (f[i - 1][j] && s1[i - 1] == s3[p]);
                }
                if (j > 0) {
                    f[i][j] = f[i][j] || (f[i][j - 1] && s2[j - 1] == s3[p]);
                }
            }
        }
        return f[n1][n2];

    }
};

int main() {
    string s1 = "aabcc";
    string s2 = "dbbca";
    string s3 = "aadbbbaccc";
    Solution s = Solution();
    cout<<s.isInterleave(s1, s2, s3);
}