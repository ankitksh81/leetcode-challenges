/*
    Climbing Stairs
    https://leetcode.com/problems/climbing-stairs/
*/

// Solution 1:

class Solution {
    int dp[50];
public:
    int solve(int n) {
        if(n == 1 || n == 2) {
            return dp[n];
        }
        if(dp[n] != -1) {
            return dp[n];
        }
        
        return dp[n] = solve(n-1) + solve(n-2);
    }
    
    int climbStairs(int n) {
        memset(dp, -1, sizeof(dp));
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        return solve(n);
    }
};

// Solution 2:

class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1);
        dp[0] = 1;
        dp[1] = 1;
        
        for(int i = 2; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        
        return dp[n];
    }
};