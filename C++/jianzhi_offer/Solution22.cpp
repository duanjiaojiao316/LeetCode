#include <iostream>
#include "../Leetcode/listNode.h"
using namespace std;


/**
 * 单链表倒数第K个节点
 * 两次遍历
*/
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* node = nullptr;
        int n = 0;
        for (node = head; node; node = node->next) {
            n++;
        }
        for (node = head; n > k; n--) {
            node = node->next;
        }
        
        return node;
    }
};

/**
 * 获取链表中倒数第K个节点
 * 快慢指针
*/

class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* p1 = head;

        for (int i = k; i > 0; i--) {
            p1 = p1->next;
        }
        ListNode* p2 = head;

        while(p1) {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p2;
    }
};