#include "treeNode.h"
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    map<int, int> valToIndex;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            valToIndex[inorder[i]] = i;
        }
        return build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }

    TreeNode* build(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd) {
        if (preStart > preEnd) {
            return nullptr;
        }
        // 根节点的值
        int rootVal = preorder[preStart];
        TreeNode* root = new TreeNode(rootVal);
        // 根节点在中序遍历中的索引
        int index = valToIndex[rootVal];
        // 左子树的大小
        int leftSize = index - inStart;
        root -> left = build(preorder, preStart + 1, preStart + leftSize, inorder, 0, index - 1);
        root -> right = build(preorder, preStart + 1 + leftSize, preEnd, inorder, index + 1, inEnd);
        return root;
    }
};

int main() {
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};
    Solution s = Solution();
    s.buildTree(preorder, inorder);
}