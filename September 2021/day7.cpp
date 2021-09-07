// Problem link: https://leetcode.com/explore/challenge/card/september-leetcoding-challenge-2021/636/week-1-september-1st-september-7th/3966/


// Solution 1: iterative

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
    ListNode* reverseList(ListNode* head) {
        ListNode *prev_node = nullptr, *next_node = nullptr;
        ListNode *cur_node = head;

        while(cur_node != nullptr) {
            next_node = cur_node->next;
            cur_node->next = prev_node;
            prev_node = cur_node;
            cur_node = next_node;
        }
        head = prev_node;
        return head;
    }
};


// Solution 2: recursive

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode *new_head = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;

        return new_head;
    }
};