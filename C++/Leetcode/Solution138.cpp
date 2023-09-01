#include "node_random.h"
#include <map>
#include <set>
using namespace std;

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // 先拷贝 next 使得新复制的所有节点都存在
        map<Node*,Node*> originToClone;

        for (Node* p = head; p; p = p->next) {
            if (!originToClone.count(p)) {
                originToClone.emplace(p, new Node(p->val));
            }
        }

        for (Node* p = head; p; p = p->next) {
            if (p->next) {
                originToClone[p]->next = originToClone
                [p->next];
            }
            
            if (p->random) {
                originToClone[p]->random = originToClone
                [p->random];
            }
        }
        return originToClone[head];
    }
};

class Solution {
public:
    map<Node*,Node*> originToClone;
    set<Node*> visited;
    Node* copyRandomList(Node* head) {
        dfs(head);
        return originToClone[head];
    }
    void dfs(Node* node) {
        if (!node) {
            return;
        }
        if (visited.count(node)) {
            return;
        }

        visited.emplace(node);
        
        if (!originToClone.count(node)) {
            originToClone.emplace(node, new Node(node->val));
        }
        Node* cloneNode = originToClone[node];

        dfs(node->next);
        cloneNode->next = originToClone[node->next];
        
        dfs(node->random);
        cloneNode->random = originToClone[node->random];
    }
};

