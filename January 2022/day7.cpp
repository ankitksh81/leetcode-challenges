/*
    Linked List Random Node
    https://leetcode.com/problems/linked-list-random-node/
*/

// Solution 1: Constant Space

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
    ListNode* Head;
    int len;
    
    int findLength(ListNode* head) {
        int l = 0;
        ListNode* temp = head;
        while(temp != nullptr) {
            l++;
            temp = temp->next;
        }
        return l;
    }
    
public:
    Solution(ListNode* head) {
        Head = head;
        srand(time(0));
        len = findLength(head);
    }
    
    int getRandom() {
        int idx = rand() % len;
        ListNode* temp = Head;
        while(idx--) {
            temp = temp->next;
        }
        return temp->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */

// Solution 2: Using Array

class Solution {
    vector<int> elements;
public:
    Solution(ListNode* head) {
        ListNode* temp = head;
        while(temp != nullptr) {
            elements.push_back(temp->val);
            temp = temp->next;
        }
        srand(time(0));
    }
    
    int getRandom() {
        int idx = rand() % elements.size();
        return elements[idx];
    }
};

// Solution 3: Reservoir Sampling Algorithm

class Solution {
    ListNode* Head;
public:
    Solution(ListNode* head) {
        Head = head;
        srand(time(0));
    }
    
    int getRandom() {
        int chosenVal = 0, idx = 1;
        ListNode* cur = Head;
        while(cur != nullptr) {
            if(rand() % idx == 0)
                chosenVal = cur->val;
            idx++;
            cur = cur->next;
        }
        return chosenVal;
    }
};