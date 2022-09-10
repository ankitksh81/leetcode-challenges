/*
	Best Time to Buy and Sell Stock IV
	https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
*/

// Solution: Dynamic Programming

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (k == 0 || prices.size() == 0) {
            return 0;
        }
        
        int n = prices.size();
        int dp[k + 1][n];
        
        for (int i = 0; i < n; i++) {
            dp[0][i] = 0;
        }
        
        for (int i = 0; i <= k; i++) {
            dp[i][0] = 0;
        }
        
        int mn = prices[0];
        for (int i = 1; i <= k; i++) {
            int mx = INT_MIN;
            for (int j = 1; j < n; j++) {
                mx = max(dp[i - 1][j - 1] - prices[j - 1], mx);
                dp[i][j] = max(dp[i][j - 1], mx + prices[j]);
            }
        }
        
        return dp[k][n - 1];
    }
};