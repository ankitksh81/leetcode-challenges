/*
    Number of Dice Rolls with Target Sum
    https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/description/
*/

// Solution: Dynamic Programming

class Solution {
    const int MOD = 1e9 + 7;
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n + 1, vector<int>(target + 1));
        dp[n][target] = 1;

        for (int diceIndex = n-1; diceIndex >= 0; diceIndex--) {
            for (int cursum = 0; cursum <= target; cursum++) {
                int ways = 0;
                for (int i = 1; i <= min(k, target - cursum); i++) {
                    if (i + cursum <= target) {
                        ways = (ways + dp[diceIndex + 1][cursum + i]) % MOD;
                    }
                }

                dp[diceIndex][cursum] = ways % MOD;
            }
        }

        return dp[0][0];
    }
};
