// Problem link: https://leetcode.com/explore/challenge/card/september-leetcoding-challenge-2021/640/week-5-september-29th-september-30th/3992/


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
    int findLength(ListNode* head) {
        int cnt = 0;
        ListNode* temp = head;
        while(temp != nullptr) {
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }
    
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int N = findLength(head);
        cout << N << endl;
        int rem = N % k;
        int noe = N / k;
        vector<ListNode*> ans(k);
        ListNode* temp = head;
        for(int i = 0; i < k; i++) {
            ListNode* cur = temp;
            for(int j = 0; j < noe + (i < rem ? 1 : 0) - 1; j++) {
                if(temp != nullptr) {
                    temp = temp->next;
                }
            }
            if(temp != nullptr) {
                ListNode* prev = temp;
                temp = temp->next;
                prev->next = nullptr;
            }
            ans[i] = cur;
        }
        return ans;
    }
};