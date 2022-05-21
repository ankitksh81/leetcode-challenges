/*
	Coint Change
	https://leetcode.com/problems/coin-change/
*/

// Solution 1: Recursion + Memoization

class Solution {
    int dp[15][10005];
public:
    long solve(vector<int>& coins, int amount, int idx) {
        if (idx == -1) {
            if (amount == 0)    return 0;
            return INT_MAX;
        }
        if (amount < 0) return INT_MAX;
        if (dp[idx][amount] != -1)  return dp[idx][amount];
        return dp[idx][amount] = min(solve(coins, amount, idx-1), 1 + solve(coins, amount - coins[idx], idx));
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        memset(dp, -1, sizeof(dp));
        long ans = solve(coins, amount, n-1);
        return ans == INT_MAX ? -1 : ans;
    }
};

// Solution 2: Dynamic Programming

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1);
        dp[0] = 0;
        
        for (int i = 1; i <= amount; i++) {
            dp[i] = INT_MAX;
            for (int coin : coins) {
                if (i - coin < 0)  continue;
                if (dp[i - coin] != INT_MAX) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};