#include "listNode.h"

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head) {
            return nullptr;
        }
        ListNode* pre = nullptr;

        while(head) {
            ListNode* next = head->next;
            head -> next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }
};