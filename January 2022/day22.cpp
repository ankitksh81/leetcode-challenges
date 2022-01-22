/*
	Stone Game IV
	https://leetcode.com/problems/stone-game-iv/
*/

// Solution: Dynamic Programming

class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> dp(n+1, false);
        for(int i = 0; i < n+1; i++) {
            if(dp[i]) {
                continue;
            }
            for(int k = 1; i + k * k <= n; k++) {
                dp[i + k*k] = true;
            }
        }
        return dp[n];
    }
};