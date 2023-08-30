#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int mod = 1e9 + 7;
        vector<int> dp (n); // dp[i]表示以arr[i]为根节点的带因子二叉树的个数
        int res = 0;
        for (int i = 0; i < n; i++) {
            dp[i] = 1;
            for (int left = 0, right = i - 1; left <= right; left++) {
                while (left <= right && arr[left] * arr[right] > arr[i]) {
                    right--; 
                } 
                if (left <= right && arr[left] * arr[right] == arr[i]) {
                    if (left != right) {
                        dp[i] = (dp[left] + dp[right] * 2) % mod;
                    } else {
                        dp[i] = (dp[left] + dp[right]) % mod;
                    }
                }
            }
            res = (res + dp[i]) % mod;
        }
        return res;

    }
};