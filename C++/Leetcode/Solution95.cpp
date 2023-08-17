#include "treeNode.h"
#include <vector>
using namespace std;

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) {
            return vector<TreeNode*>(0);
        }
        return build(1,n);
    }

    vector<TreeNode*> build (int lo, int hi) {
        vector<TreeNode*> res;
        if (lo > hi) {
            return res;
        }

        for (int i = lo; i <= hi; i++) {
            vector<TreeNode*> leftTree = build(lo, i - 1);
            vector<TreeNode*> rightTree = build(i + 1, hi);
            for (TreeNode* left : leftTree) {
                for (TreeNode* right : rightTree) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};

int main () {
    Solution s = Solution();
    s.generateTrees(5);
    return 0;
}