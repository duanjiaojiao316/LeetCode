#include "listNode.h"
 
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (!root1 && root2) {
            return root2;
        }
        if (!root2 && root1) {
            return root1;
        }
        TreeNode* mergedTree = new TreeNode(root1->val + root2->val);

        mergedTree->left = mergeTrees(root1->left, root2->left);
        mergedTree->right = mergeTrees(root1->right, root2->right);
        return mergedTree;

    }
};