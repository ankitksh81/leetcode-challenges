/*
    Convert binary number in a linked list to integer
    https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/
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
    int getDecimalValue(ListNode* head) {
        string s = "";
        ListNode* temp = head;
        while(temp != nullptr) {
            s += (temp->val + '0');
            temp = temp->next;
        }
        
        reverse(s.begin(), s.end());
        int ans = 0;
        for(int i = 0; i < s.length(); i++) {
            ans += (s[i] - '0') * (1 << (i));
        }
        
        return ans;
    }
};

// Solution 2:

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int val = head->val;
        while(head->next != nullptr) {
            val = (val << 1) | head->next->val;
            head = head->next;
        }
        
        return val;
    }
};

// Solution 3:

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int val = head->val;
        while(head->next != nullptr) {
            val = val * 2 + head->next->val;
            head = head->next;
        }
        
        return val;
    }
};