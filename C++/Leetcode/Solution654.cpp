#include "treeNode.h"
#include <vector>
using namespace std;

class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return build(nums, 0, nums.size() - 1);
    }

    TreeNode* build(vector<int>& nums, int lo, int hi) {
        if (lo > hi) {
            return nullptr;
        }

        int index = -1; // 最大数在nums中的索引
        int maxVal = -1; // 最大的数

        for (int i = lo; i <= hi; i++) {
            if (nums[i] > maxVal) {
                index = i;
                maxVal = nums[i];
            }
        }
        TreeNode* root = new TreeNode(maxVal);
        root->left = build(nums, lo, index - 1);
        root->right = build(nums, index + 1, hi);

        return root;
    }
};