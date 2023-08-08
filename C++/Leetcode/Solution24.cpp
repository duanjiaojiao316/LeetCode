
struct  ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
    /* data */
};

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
