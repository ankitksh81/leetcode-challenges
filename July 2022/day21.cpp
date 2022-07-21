/*
	Reverse Linked List II
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || !head->next) return head;
        
        ListNode* prev = nullptr, *cur = head;
        while (left > 1) {
            prev = cur;
            cur = cur->next;
            left--;
            right--;
        }
        
        ListNode* headPtr = prev, *tailPtr = cur;
        ListNode* nextPtr = nullptr;
        
        while (right > 0) {
            nextPtr = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nextPtr;
            right--;
        }
        
        if (headPtr != nullptr) {
            headPtr->next = prev;
        }
        else {
            head = prev;
        }
        
        tailPtr->next = cur;
        return head;
    }
};
*/