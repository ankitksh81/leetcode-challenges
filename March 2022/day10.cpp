/*
	Add Two Numbers
	https://leetcode.com/problems/add-two-numbers/
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* ptr3 = dummy;
        int carry = 0;
        
        while(l1 || l2 || carry) {
            int sum = 0;
            if(l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            
            if(l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            
            sum += carry;
            carry = sum / 10;
            
            ptr3->next = new ListNode(sum % 10);
            ptr3 = ptr3->next;
        }
        
        return dummy->next;
    }
};