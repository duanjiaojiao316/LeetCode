#include "listNode.h"

class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head) {
            return;
        }
        // 获取中间节点
        ListNode* mid = middleNode(head);

        // 反转后半个链表
        ListNode* reverse = reverseList(mid->next);

        mid->next = nullptr;

        // 合并两个链表
        mergeList(head, reverse);
        head = head->next;
        
    }

    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* reverseList(ListNode* head) {
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

    ListNode* mergeList(ListNode* l1, ListNode* l2) {
        ListNode* head = l1;
        while (l1 && l2) {
            ListNode* tmp_1 = l1->next;

            ListNode* tmp_2 = l2->next;
            l1->next = l2;
            l2 -> next = tmp_1;
            l2 = tmp_2;
            l1 = l1->next->next;
        }
        return l1;
    }
};

int main () {
    ListNode* l1 = new ListNode(1);
    ListNode* l2 = new ListNode(2);
    ListNode* l3 = new ListNode(3);
    ListNode* l4 = new ListNode(4);
    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    Solution s = Solution();
    s.reorderList(l1);
    return 0;
}