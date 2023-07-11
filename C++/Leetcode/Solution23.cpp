#include <vector>
#include <queue>
#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
/**
 * 合并K个有序链表, 方法一：顺序合并
*/
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) {
            return nullptr;
        }
        ListNode* ans = nullptr;

        for (int i = 0; i < lists.size(); i++) {
            ans = mergeTwoLists(ans, lists[i]);
        }
        return ans;

    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) {
            return list2;
        }
        if (list2 == nullptr) {
            return list1;
        }
        ListNode *result;

        if (list1->val < list2->val){
            result = list1;
            result->next = mergeTwoLists(list1->next, list2);
        } else {
            result = list2;
            result->next = mergeTwoLists(list1, list2->next);
        }

        return result;
    }
};


class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return merge(lists, 0, lists.size() - 1);
    }

    ListNode* merge(vector<ListNode*>& lists, int left, int right) {
        if (left == right) {
            return lists[left];
        } else if (left > right) {
            return nullptr;
        } else {
            int mid = (left + right) >> 1;
            return mergeTowLists(merge(lists, left, mid), merge(lists, mid + 1, right));
        }
    }

    ListNode* mergeTowLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* p = dummy;

        ListNode* p1 = list1;
        ListNode* p2 = list2;
        while(p1 != nullptr && p2 != nullptr){
            if (p1->val < p2->val) {
                p->next = p1;
                p1 = p1->next;
            } else {
                p->next = p2;
                p2 = p2->next;
            }
            p = p->next;
        }
        p->next = (p1 ? p1 : p2);
        return dummy->next;

    }
};

class Solution {
public:
    struct comp{
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }

    };

    priority_queue<ListNode*, vector<ListNode*>, comp> q;

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for(auto node: lists) {
            if (node) q.push(node);
        }

        ListNode* head = new ListNode();
        ListNode* tail = head;
        while (!q.empty()) {
            ListNode* node = q.top();
            q.pop();
            tail->next = node;
            tail = tail->next;
            if (node->next) q.push(node->next);
        }
        return head->next;
    }
};