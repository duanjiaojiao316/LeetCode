#include "treeNode.h"
#include <algorithm>
#include <stack>
using namespace std;

class Solution {
public:
    int res = 0;
    stack<int> path_max; // 路径中的最大值
    int goodNodes(TreeNode* root) {
        dfs(root);
        return res;
    }

    void dfs(TreeNode* root) {
        if (!root) {
            return;
        }
        if (path_max.empty()) {
            path_max.push(root->val);
            res++;
        } else{
            if (root->val >= path_max.top()) {
                res++;
            }
            path_max.push(max(path_max.top(), root->val));
        }
        
        dfs(root->left);
        dfs(root->right);
        path_max.pop();

    }
};

int main() {
    Solution s = Solution();
    TreeNode* t1 = new TreeNode(3);
    TreeNode* t2 = new TreeNode(3);
    TreeNode* t3 = new TreeNode(4);
    TreeNode* t4 = new TreeNode(2);
    TreeNode* t5 = new TreeNode(1);
    TreeNode* t6 = new TreeNode(5);
    t1->left = t2;
    t2->right = t4;
    t2->left = t3;
    s.goodNodes(t1);
    return 0;
}