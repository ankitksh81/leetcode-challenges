/*
	Champagne Tower
	https://leetcode.com/problems/champagne-tower/
*/

// Solution: Simulation with DP

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> dp(102, vector<double>(102));
        dp[0][0] = (double)poured;
        
        for (int r = 0; r <= query_row; r++) {
            for (int c = 0; c <= r; c++) {
                double q = (dp[r][c] - 1.0) / 2.0;
                if (q > 0) {
                    dp[r + 1][c] += q;
                    dp[r + 1][c + 1] += q;
                }
            }
        }
        
        return min((double)1, dp[query_row][query_glass]);
    }
};