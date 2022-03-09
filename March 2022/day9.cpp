/*
	Remove Duplicates from Sorted List II
	https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* cur = head, *prev = dummy;
        
        while(cur && cur->next) {
            if(cur->val == cur->next->val) {
                ListNode* temp = cur->next;
                while(temp && temp->val == cur->val) {
                    temp = temp->next;
                }
                prev->next = temp;
                cur = temp;
            }
            else {
                prev = cur;
                cur = cur->next;
            }
        }
        
        return dummy->next;
    }
};