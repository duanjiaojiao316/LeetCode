#include "../Leetcode/listNode.h"

class Solution {
public:
    ListNode*detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast  && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) break;
        }
        if (fast == nullptr || fast->next == nullptr) {
            return nullptr;
        }
        slow = head;

        while (slow != fast) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;

    }
};