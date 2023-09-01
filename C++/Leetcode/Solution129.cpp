#include "treeNode.h"
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> tmp; // 记录产生的数字
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }

    int dfs(TreeNode* root, int preSum) {
        if (!root) {
            return 0;
        }
        int sum = preSum * 10  + root->val;
        if (!root->left && !root->right) {
            return sum;
        } else {
            return dfs(root->left, sum) + dfs(root->right, sum);
        }

    }
};