#include "treeNode.h"
#include <vector>
#include <queue>z
using namespace std;

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> q;
        vector<double> averages;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            double average = 0;
            for (int i = 0; i < size; i++) {
                TreeNode* top = q.front();
                q.pop();
                average += top->val;
                if (top->left) q.emplace(top->left);
                if (top->right) q.emplace(top->right);
            }
            averages.push_back(average / size);

        }
        return averages;

    }
};