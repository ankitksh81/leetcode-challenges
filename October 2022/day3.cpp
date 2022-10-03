/*
	Minimum Time to Make Rope Colorful
	https://leetcode.com/problems/minimum-time-to-make-rope-colorful/description/
*/

// Solution 1: Greedy + Min Heap

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int N = colors.length();
        priority_queue<int, vector<int>, greater<int>> pq;

        int cost = 0;
        pq.push(neededTime[0]);
        for (int i = 1; i <= N; i++) {
            if (i == N) {
                while (pq.size() > 1) {
                    cost += pq.top();
                    pq.pop();
                }
                break;
            }
            if (colors[i] == colors[i-1]) {
                pq.push(neededTime[i]);
            }
            else {
                while (pq.size() > 1) {
                    cost += pq.top();
                    pq.pop();
                }
                if (!pq.empty()) {
                    pq.pop();
                }
                pq.push(neededTime[i]);
            }
        }

        return cost;
    }
};


// Solution 2: Two Pointer

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int N = neededTime.size();
        int res = 0, curmax = 0;

        for (int i = 0; i < N; i++) {
            if (i > 0 && colors[i] != colors[i-1]) {
                curmax = 0;
            }

            res += min(curmax, neededTime[i]);
            curmax = max(neededTime[i], curmax);
        }

        return res;
    }
};