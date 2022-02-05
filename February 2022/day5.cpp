/*
	Merge k Sorted Lists
	https://leetcode.com/problems/merge-k-sorted-lists/
*/

// Solution 1: Priority Queue

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) {
            return nullptr;
        }
        if(lists.size() == 1 && lists[0] == nullptr) {
            return nullptr;
        }
        
        auto cmp = [&](ListNode* a, ListNode* b) {
            return a->val > b->val;
        };
        
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
        
        for(int i = 0; i < lists.size(); i++) {
            if(lists[i]) {
                pq.push(lists[i]);
            }
        }
        ListNode* head = new ListNode(-1);
        ListNode* cur = head;
        while(!pq.empty()) {
            auto node = pq.top();
            pq.pop();
            cur->next = node;
            cur = cur->next;
            
            if(node->next != nullptr) {
                pq.push(node->next);
            }
        }
        cur->next = nullptr;
        return head->next;
    }
};

// Solution 2: Merge 2 Lists (k-1) times

class Solution {
public:
    ListNode* merge2Lists(ListNode* p1, ListNode* p2) {
        ListNode front(0);
        ListNode* back = &front;
        while(p1 && p2) {
            if(p1->val < p2->val) {
                back->next = p1;
                p1 = p1->next;
            }
            else {
                back->next = p2;
                p2 = p2->next;
            }
            back = back->next;
        }
        back->next = p1 ? p1 : p2;
        return front.next;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) {
            return nullptr;
        }
        
        for(int interval = 1; interval < lists.size(); interval *= 2) {
            for(int index = 0; index + interval < lists.size(); index = index + interval * 2) {
                lists[index] = merge2Lists(lists[index], lists[index + interval]);
            }
        }
        return lists[0];
    }
};