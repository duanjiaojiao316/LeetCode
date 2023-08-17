#include "listNode.h"

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr) {
            if (slow->val != fast->val) {
                slow->next = fast;
                slow = slow->next;
            } 
            fast = fast->next;
        }
        slow->next = nullptr;
        return head;
    }
};

int main () {
    return 0;
}