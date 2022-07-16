/*
	Out of Boundary Paths
	https://leetcode.com/problems/out-of-boundary-paths/
*/

// Solution: Dynamic Programming

class Solution {
    const int MOD = (int)1e9+7;
    int dir[4][2] = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
    int dp[55][55][55];
public:
    int helper(int m, int n, int N, int r, int c) {
        if(r < 0 || c < 0 || r >= m || c >= n) {
            return 1;
        }
        if(N == 0) {
            return 0;
        }
        
        if(dp[r][c][N] != -1) {
            return dp[r][c][N];
        }
        
        long paths = 0;
        for(int i = 0; i < 4; i++) {
            int x = r + dir[i][0];
            int y = c + dir[i][1];
            paths = paths + helper(m, n, N-1, x, y) % MOD;
        }
        
        return dp[r][c][N] = paths % MOD;
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp, -1, sizeof(dp));
        return helper(m, n, maxMove, startRow, startColumn);
    }
};