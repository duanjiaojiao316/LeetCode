#include <stack>
using namespace std;

class MinStack {
public:
    // 阶段性的记录栈中的最小值
    stack<int> min;
    // 记录栈中的所有元素
    stack<int> elements;
    MinStack() {}
    
    void push(int val) {
        elements.push(val); 
        if (min.empty() || val <= min.top()) {
            min.push(val);
        } 
    }
    
    void pop() {
        if (min.top() == elements.top()) {
            min.pop();
        }
        elements.pop();
    }
    
    int top() {
        return elements.top();
    }
    
    int getMin() {
        return min.top();
    }
};