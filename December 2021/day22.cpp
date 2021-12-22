/*
    Reorder list
    https://leetcode.com/problems/reorder-list/
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
    void reorderList(ListNode* head) {
        if(head == nullptr || head->next == nullptr || head->next->next == nullptr) {
            return;
        }
        
        int size = 0;
        ListNode* temp = head;
        stack<ListNode*> st;
        while(temp != nullptr) {
            st.push(temp);
            size++;
            temp = temp->next;
        }
        
        ListNode* ptr = head, *ptr_next;
        for(int i = 0; i < size / 2; i++) {
            ptr_next = ptr->next;
            ptr->next = st.top();
            st.pop();
            ptr->next->next = ptr_next;
            ptr = ptr->next->next;
        }
        ptr->next = nullptr;
    }
};

// SOlution 2:

class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* fast = head, *slow = head;
        // find middle of the linked list
        while(fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // reverse the second half of the linked list
        ListNode* prev = nullptr, *cur = slow, *temp;
        while(cur != nullptr) {
            temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }
        
        // merge the linked list
        ListNode* first = head, *second = prev;
        while(second->next != nullptr) {
            temp = first->next;
            first->next = second;
            first = temp;
            
            temp = second->next;
            second->next = first;
            second = temp;
        }
    }
};