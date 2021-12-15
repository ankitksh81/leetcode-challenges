/*
    Insertion sort list
    https://leetcode.com/problems/insertion-sort-list/
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
    ListNode* insertionSortList(ListNode* head) {
        if(head->next == nullptr) {
            return head;
        }
        
        ListNode* dummy = new ListNode();
        ListNode* cur = head;
        
        while(cur != nullptr) {
            ListNode* prev = dummy;
            while(prev->next != nullptr && prev->next->val < cur->val) {
                prev = prev->next;
            }
            
            ListNode* next = cur->next;
            cur->next = prev->next;
            prev->next = cur;
            cur = next;
        }
        
        return dummy->next;
    }
};