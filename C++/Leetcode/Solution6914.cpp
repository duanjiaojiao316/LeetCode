#include "listNode.h"

class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        if (!head) {
            return nullptr;
        }
        ListNode* reverse = reverseList(head);
        ListNode* cur = reverse;
        int mul = 0;
        while (cur) {
            int res = cur->val * 2 + mul;
            mul = res / 10;
            cur->val = res % 10;
            cur = cur->next;
        }

        ListNode* res = nullptr;
        if (mul) {
            ListNode* newMul = new ListNode(mul);
            newMul -> next = reverseList(reverse);
            res = newMul;
        } else {
            res = reverseList(reverse);
        }
        return res;

    }

    ListNode* reverseList (ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while (cur) {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre; 
    }
};

int main() {
    ListNode* n1 = new ListNode(9);
    ListNode* n2 = new ListNode(9);
    n1->next = n2;
    ListNode* n3 = new ListNode(9);
    n2->next = n3;
    Solution s = Solution();
    s.doubleIt(n1);
    
}