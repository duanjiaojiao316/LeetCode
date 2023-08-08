#include <algorithm>
using namespace std;

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (!root) {
            return true;
        } else {
            if (isBalanced(root->left) && isBalanced(root->right)) {
                if(abs(height(root->left) - height(root->right)) <=1){
                    return true;
                }
            }
            return false;
        }
    }
    int height(TreeNode* root) {
        if (!root) {
            return 0;
        } else {
            return max(height(root->left), height(root->right));
        }
    }
};