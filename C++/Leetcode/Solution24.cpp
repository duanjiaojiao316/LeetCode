#include "listNode.h"

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head -> next) {
            return head;
        }

        
        ListNode* zero = new ListNode(0);
        zero->next = head;
        ListNode* pre = zero;

        ListNode* first;
        ListNode* second;
        while (pre->next && pre->next->next) { 

            first = pre->next;
            second = first->next;
            // 反转一对节点
            pre->next = second;
            first->next = second->next;
            second->next = first;
            
            pre = first;
        }
        return zero->next;
    }
};
