/*
	Palindrome Linked List
	https://leetcode.com/problems/palindrome-linked-list/
*/

// Solution: Reversing 2nd half of Linked List

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
using ln = ListNode*;
class Solution {
public:
    ln reverse(ListNode* &node) {
        ListNode* cur = node, *prev = nullptr, *next_ptr = nullptr;
        while(cur != nullptr) {
            next_ptr = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next_ptr;
        }
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        if(head == nullptr || head->next == nullptr) {
            return true;
        }
        ListNode* slow = head, *fast = head;
        while(fast->next != nullptr && fast->next->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        slow->next = reverse(slow->next);
        slow = slow->next;
        while(slow != nullptr) {
            if(head->val != slow->val) {
                return false;
            }
            head = head->next;
            slow = slow->next;
        }
        return true;
    }
};