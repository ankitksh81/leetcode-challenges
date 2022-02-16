/*
	Swap Nodes in Pairs
	https://leetcode.com/problems/swap-nodes-in-pairs/
*/

// Solution 1: Recursion

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
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr) {
            return head;
        }
        
        ListNode* temp = head->next;
        
        head->next = swapPairs(head->next->next);
        temp->next = head;
        return temp;
    }
};

// Solution 2: Iterative

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
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* newHead = head;
        ListNode* last = nullptr;
        ListNode* cur = head;
        
        while(cur != nullptr) {
            ListNode* a = cur;
            ListNode* b = cur->next;
            
            if(b == nullptr) {
                break;
            }
            
            ListNode* next = cur->next->next;
            
            if(last == nullptr) {
                newHead = b;
            }
            else {
                last->next = b;
            }
            b->next = a;
            a->next = next;
            last = a;
            cur = next;
        }
        
        return newHead;
    }
};