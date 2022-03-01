/*
	Counting Bits
	https://leetcode.com/problems/counting-bits/
*/

// Solution: DP + Least Significant Bit

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n+1);
        for(int x = 1; x <= n; x++) {
            dp[x] = dp[x >> 1] + (x & 1);
        }
        return dp;
    }
};