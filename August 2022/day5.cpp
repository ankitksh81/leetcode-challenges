/*
	Combination Sum IV
	https://leetcode.com/problems/combination-sum-iv/
*/

// Solution 1: Recursion + Memoization

class Solution {
public:
    int solve(vector<int>& nums, int target, vector<int>& dp) {
        if (target == 0) return 1;
        if (dp[target] != -1) return dp[target];
        
        dp[target] = 0;
        for (auto &num : nums) {
            if (num <= target) {
                dp[target] += solve(nums, target - num, dp);
            }
        }
        return dp[target];
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, -1);
        return solve(nums, target, dp);
    }
};


// Solution 2: Dynamic Programming

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned long long> dp(target + 1);
        dp[0] = 1;
        for (int i = 1; i <= target; i++) {
            for (auto &num : nums) {
                if (num <= i) {
                    dp[i] += dp[i - num];
                }
            }
        }
        
        return dp[target];
    }
};