/*
	Partition List
	https://leetcode.com/problems/partition-list/
*/

// Solution: Two Pointers

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (!head) return nullptr;
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* ptr = dummy;
        ListNode* cur = head, *prev = dummy;
        
        while (cur && cur->val < x) {
            prev = cur;
            cur = cur->next;
            ptr = ptr->next;
        }
        
        if (!cur) return  head;
        
        while (cur) {
            if (cur->val < x) {
                ListNode* next = cur->next;
                ListNode* ptr_next = ptr->next;
                prev->next = next;
                ptr->next = cur;
                cur->next = ptr_next;
                cur = next;
                ptr = ptr->next;
            }
            else {
                prev = cur;
                cur = cur->next;
            }
        }
        
        return dummy->next;
    }
};