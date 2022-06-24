/*
	Construct Target Array With Multiple Sums
	https://leetcode.com/problems/construct-target-array-with-multiple-sums/
*/

// Solution: Max Heap

class Solution {
public:
    bool isPossible(vector<int>& target) {
        if (target.size() == 1) {
            return target[0] == 1;
        }
        
        long sum = accumulate(target.begin(), target.end(), 0L);
        priority_queue<int> pq;
        
        for (int i = 0; i < target.size(); i++) {
            pq.push(target[i]);
        }
        
        int cnt = 0;
        while (pq.top() > 1) {
            int ele = pq.top();
            pq.pop();
            int rest = sum - ele;
            if (rest == 1) {
                return true;
            }
            int x = ele % rest;
            if (x == 0 || x == ele) {
                return false;
            }
            pq.push(x);
            sum = sum - ele + x;
        }
        
        return true;
    }
};