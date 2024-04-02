#include<unordered_map>
#include "treeNode.h"
using namespace std;

class Solution {
public:
    unordered_map<TreeNode*, int> s, n;
    int rob(TreeNode* root) {
        dfs(root);
        return max(s[root], n[root]);
    }

    void dfs(TreeNode* node) {
        if (node == nullptr) {
            return;
        }

        dfs(node->left);
        dfs(node->right);

        s[node] = node->val + n[node->left] + n[node->right];
        n[node] = max(s[node->left], n[node->left]) + max(s[node->right], n[node->right]);
    } 
};