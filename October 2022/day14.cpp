/*
	Delete the Middle Node of a Linked List
	https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/description/
*/

// Solution: Tortoise & Hare

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
    ListNode* deleteMiddle(ListNode* head) {
        if (!head || !head->next) return nullptr;
        if (!head->next->next) {
            head->next = head->next->next;
            return head;
        }
        
        ListNode *fast = head;
        ListNode *slow = head;

        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        slow->val = slow->next->val;
        slow->next = slow->next->next;

        return head;
    }
};