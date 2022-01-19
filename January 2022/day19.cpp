/*
	Linked List Cycle II
	https://leetcode.com/problems/linked-list-cycle-ii/
*/

// Solution: Fast & Slow Pointer

using ln = ListNode*;
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr || head->next == nullptr) {
            return nullptr;
        }
        
        ln slow = head;
        ln fast = head;
        ln ptr = head;
        bool flag = false;
        while(fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) {
                flag = true;
                break;
            }
        }
        
        if(flag) {
            while(slow != ptr) {
                ptr = ptr->next;
                slow = slow->next;
            }
            
            return ptr;
        }
        
        return nullptr;
    }
};