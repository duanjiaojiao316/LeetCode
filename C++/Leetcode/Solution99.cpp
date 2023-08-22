#include "treeNode.h"
#include <algorithm>
using namespace std;

class Solution {
public:
    TreeNode* firstNode;
    TreeNode* secondNode;
    TreeNode* preNode;
    void recoverTree(TreeNode* root) {
        // 中序遍历搜索二叉树找出需要交换的两个节点
        order(root);
        swap (firstNode-> val, secondNode->val);

        // int tmp = firstNode;
        // firstNode -> val = secondNode -> val;
        // secondNode -> val = tmp;
    }
private:
    void order (TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        order(root->left);
        if (firstNode == nullptr && preNode != nullptr && preNode-> val > root -> val) {
            firstNode = preNode;
        }
        if (firstNode != nullptr && preNode != nullptr && preNode -> val > root -> val) {
            secondNode = root;
        }
        preNode = root;
        order(root->right);

    }
};