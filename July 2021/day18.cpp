/* Day 18
    Problem link: https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/610/week-3-july-15th-july-21st/3818/
*/


// Solution 1:

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head, *prev, *next_node, *start_prev, *start_curr;
        int nodes = 0;
        while(curr != nullptr){
            nodes++;
            curr = curr->next;
        }
        curr = head;
        nodes = nodes / k;
        for(int i = 0; i < nodes; i++){
            prev = nullptr;
            start_curr = curr;

            for(int j = 0; j < k; j++) {
                next_node = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next_node;
            }
            if(i == 0)
                head = prev;
            if(i > 0)
                start_prev->next = prev;
            start_prev = start_curr;
        }

        if(start_curr){
            start_curr->next = curr;
        }
        return head;
    }
};


// Solution 2:

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* prev = NULL, *curr = head, *nxt=NULL;
        int count = 0;
        ListNode* cursor = head;
        for(int i = 0; i < k; i++){
            if(cursor == nullptr)
                return head;
            cursor = cursor->next;
        }
        while(curr!=NULL && count<k){
            nxt = curr -> next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
            count++;
        }
        if(nxt!=NULL){
            head-> next = reverseKGroup(curr,k);
        }
        return prev;
    }
};
