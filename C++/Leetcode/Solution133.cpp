#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    // 重点：怎么在遍历的过程中避免死循环,创建一个map记录已经克隆的节点，避免重复创建节点进入送循环
    unordered_map<Node*,Node*> hasCloned;
    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return node;
        }
        if (hasCloned.find(node) != hasCloned.end()) {
            return hasCloned[node];
        }

        Node* cloneNode = new Node(node->val);
        hasCloned[node] = cloneNode;

        for (Node* neighbor : node->neighbors) {
            cloneNode->neighbors.emplace_back(cloneGraph(neighbor));
        }
        return cloneNode;
    }
};

class Solution {
public:
    // 重点：怎么在遍历的过程中避免死循环,创建一个map记录已经克隆的节点，避免重复创建节点进入送循环
    unordered_map<int,Node*> hasCloned;
    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return node;
        }
        if (hasCloned.find(node->val) != hasCloned.end()) {
            return hasCloned[node->val];
        }

        Node* cloneNode = new Node(node->val);
        hasCloned[node->val] = cloneNode;

        for (Node* neighbor : node->neighbors) {
            cloneNode->neighbors.emplace_back(cloneGraph(neighbor));
        }
        return cloneNode;
    }
};


// BFS 广度优先遍历使用队列
class Solution {
public:
    // 
    unordered_map<int,Node*> hasCloned;
    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return node;
        }
        if (hasCloned.find(node->val) != hasCloned.end()) {
            return hasCloned[node->val];
        }
        queue<Node*> q; // q中存储克隆前的对象，方便遍历节点的邻接
        q.push(node);

        Node* cloneNode = new Node(node->val);
        hasCloned[node->val] = cloneNode;
        

        while (!q.empty()) {
            Node* n = q.front();
            q.pop();
            for (Node* neighbor: n->neighbors) {
                if (hasCloned.find(neighbor->val) == hasCloned.end()) {
                    hasCloned[neighbor->val] =  new Node(neighbor->val);
                    q.push(neighbor);
                }
                hasCloned[n->val]->neighbors.emplace_back(hasCloned[neighbor->val]);
            }
            
        }
        return cloneNode;
    }
};