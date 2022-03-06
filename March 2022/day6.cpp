/*
	Count All Valid Pickup and Delivery Options
	https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/
*/

// Solution 1: Dynamic Programming

class Solution {
public:
    int countOrders(int n) {
        const int MOD = 1e9+7;
        vector<vector<long>> dp(n + 1, vector<long>(n + 1, 0));
        
        for(int unpicked = 0; unpicked <= n; unpicked++) {
            for(int undelivered = unpicked; undelivered <= n; undelivered++) {
                if(unpicked == 0 && undelivered == 0) {
                    dp[unpicked][undelivered] = 1;
                    continue;
                }
                
                if(unpicked > 0) {
                    dp[unpicked][undelivered] += unpicked * dp[unpicked - 1][undelivered];
                }
                
                dp[unpicked][undelivered] %= MOD;
                
                if(undelivered > unpicked) {
                    dp[unpicked][undelivered] += (undelivered - unpicked) * dp[unpicked][undelivered - 1];
                }
                dp[unpicked][undelivered] %= MOD;
            }
        }
        
        return dp[n][n];
    }
};

// Solution 2: Permutation

class Solution {
public:
    int countOrders(int n) {
        long ans = 1;
        const int MOD = 1e9 + 7;
        
        for(int i = 1; i <= n; i++) {
            ans = ans * i;
            ans = ans * (2 * i - 1);
            ans %= MOD;
        }
        
        return ans;
    }
};