/*
	Min Cost Climbing Stairs
	https://leetcode.com/problems/min-cost-climbing-stairs/
*/

// Solution 1: Dynamic Programming

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int size = cost.size();
        if(size < 2) {
            return cost[0];
        }
        
        vector<int> dp(size + 1);
        
        for(int i = 2; i <= size; i++) {
            dp[i] = min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2]);
        }
        
        return dp[size];
    }
};


// Solution 2: Dynamic Programming with Constant Space

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int size = cost.size();
        if(size < 2) {
            return cost[0];
        }
        
        int first = 0, second = 0;
        
        for(int i = 2; i <= size; i++) {
            int temp = min(first + cost[i-2], second + cost[i-1]);
            first = second;
            second = temp;
        }
        
        return second;
    }
};