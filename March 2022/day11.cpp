/*
	Rotate List
	https://leetcode.com/problems/rotate-list/
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) {
            return head;
        }
        int len = 0;
        ListNode* ptr = head;
        while(ptr->next) {
            len++;
            ptr = ptr->next;
        }
        len++;
        k = k % len;
        
        int n = len - k;
        ptr->next = head;
        ptr = head;
        
        for(int i = 0; i < n-1; i++) {
            ptr = ptr->next;
        }
        ListNode* temp = ptr->next;
        ptr->next = nullptr;
        return temp;
    }
};