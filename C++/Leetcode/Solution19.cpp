
/**
 * 删除单链表倒数第n个节点
*/
#include "listNode.h"

class Solution {
    public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* fast = dummy;
        ListNode* slow = dummy;

        for (int i = 0; i < n && fast != nullptr; i++) {
            fast = fast->next;
        }
        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* delect = slow->next;
        slow->next = delect->next;
        return dummy->next;

    }
};