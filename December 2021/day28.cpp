/*
    Middle of the linked list
    https://leetcode.com/problems/middle-of-the-linked-list/
*/

// Solution:

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(head->next == nullptr) {
            return head;
        }
        ListNode* ptr1 = head;
        ListNode* ptr2 = head->next;
        while(ptr2->next != nullptr && ptr2->next->next != nullptr) {
            ptr1 = ptr1->next;
            ptr2= ptr2->next->next;
        }
        return ptr1->next;
    }
};