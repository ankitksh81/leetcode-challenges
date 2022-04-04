/*
	Swapping Nodes in a Linked List
	https://leetcode.com/problems/swapping-nodes-in-a-linked-list/
*/

// Solution 1:

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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* first = nullptr, *last = head;
        int K = 0, len = 0;
        for(ListNode* cur = head; cur != nullptr; cur = cur->next) {
            if(++K == k) {
                first = cur;
            }
            len++;
        }
        
        for(int i = 0; i < len - k; i++) {
            last = last->next;
        }
        
        swap(first->val, last->val);
        return head;
    }
};