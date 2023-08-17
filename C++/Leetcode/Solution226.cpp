#include <iostream>
#include "treeNode.h"
using namespace std;


/// @brief 翻转二叉树

class Solution226{
    public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr){
            return nullptr;
        }
        TreeNode *left = invertTree(root->left);
        TreeNode *right = invertTree(root->right);

        root->left = right;
        root->right = left;

        return root;
    }
};

int main(){
    cout<<"leetcode 226"<<endl;
    return 0;
}