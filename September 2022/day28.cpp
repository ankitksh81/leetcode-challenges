/*
        Remove Nth Node From End of List
        https://leetcode.com/problems/remove-nth-node-from-end-of-list/
*/

// Solution: Tortoise & Hare Method

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = new ListNode();
        temp->next = head;
        ListNode* slow = temp, *fast = temp;
        
        for(int i = 0; i < n; i++) {
            fast = fast->next;
        }
        
        while(fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
        
        slow->next = slow->next->next;
        return temp->next;
    }
};
