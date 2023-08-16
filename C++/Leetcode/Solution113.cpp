#include <vector>
#include "treeNode.h"
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        


    }

    void dfs (TreeNode* root, int targetSum) {
        if (!root) {
            return;
        }
        path.push_back(root->val);
        targetSum -= root->val;
        if (!root -> left && !root->right && targetSum == 0) {
            res.push_back(path);
        }
        dfs(root->left, targetSum);
        dfs(root->right, targetSum);
        path.pop_back();

    }
};