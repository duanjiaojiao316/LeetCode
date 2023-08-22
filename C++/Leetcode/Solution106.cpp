#include "treeNode.h"
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    unordered_map<int, int> inorder_index;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i = 0; i < inorder.size(); i++) {
            inorder_index[inorder[i]] = i;
        }
        return build(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);

    }

    TreeNode* build(vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder, int postStart, int postEnd) {
        if (inStart > inEnd) {
            return nullptr;
        }

        int rootVal = postorder[postEnd];
        int index = inorder_index[rootVal];
        int rightSize = inEnd - index;

        TreeNode* root = new TreeNode(rootVal);

        root->left = build();
        root->right = build();

    }
};