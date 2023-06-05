struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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