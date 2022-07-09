/*
	Jump Game VI
	https://leetcode.com/problems/jump-game-vi/
*/

// Solution 1: Dynamic Programming + Deque

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> score(n);
        score[0] = nums[0];
        deque<int> dq;
        dq.push_back(0);
        for (int i = 1; i < n; i++) {
            while (!dq.empty() && dq.front() < i - k) {
                dq.pop_front();
            }
            score[i] = score[dq.front()] + nums[i];
            while (!dq.empty() && score[i] >= score[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        return score[n - 1];
    }
};


// Solution 2: Dynamic Programming + Priority Queue

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> score(n);
        score[0] = nums[0];
        priority_queue<pair<int, int>> priorityQueue;
        priorityQueue.push({nums[0], 0});
        for (int i = 1; i < n; i++) {
            while (priorityQueue.top().second < i - k) {
                priorityQueue.pop();
            }
            score[i] = nums[i] + score[priorityQueue.top().second];
            priorityQueue.push({score[i], i});
        }
        return score[n - 1];
    }
};