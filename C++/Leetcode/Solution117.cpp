#include "node.h"
#include <queue>
using namespace std;

class Solution {
public:
    queue<Node*> q;
    Node* connect(Node* root) {
        if (!root) {
            return nullptr;
        }
        q.push(root);

        while(!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                Node* node = q.front();
                q.pop();
                if (i < size - 1) {
                    node->next = q.front();
                }
                if (node->left)  q.push(node->left);
                if (node ->right) q.push(node->right);
            }
        }
        return root;
    }
};