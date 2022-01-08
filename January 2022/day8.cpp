/*
    Cherry Pickup II
    https://leetcode.com/problems/cherry-pickup-ii/
*/

// Solution 1: Top Down DP

class Solution {
    vector<vector<vector<int>>> dp;
    vector<vector<int>> grid;
public:
    int solve(int r, int c1, int c2) {
        if(c1 < 0 || c1 >= grid[0].size() || c2 < 0 || c2 >= grid[0].size()) {
            return 0;
        }
        if(dp[r][c1][c2] != -1) {
            return dp[r][c1][c2];
        }
        
        int res = 0;
        res += grid[r][c1];
        if(c1 != c2) {
            res += grid[r][c2];
        }
        
        if(r != grid.size()-1) {
            int mx = 0;
            for(int nc1 = c1-1; nc1 <= c1+1; nc1++) {
                for(int nc2 = c2-1; nc2 <= c2+1; nc2++) {
                    mx = max(mx, solve(r+1, nc1, nc2));
                }
            }
            res += mx;
        }
        return dp[r][c1][c2] = res;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        this->grid = grid;
        int m = grid.size(), n = grid[0].size();
        dp.assign(m, vector<vector<int>>(n, vector<int>(n, -1)));
        return solve(0, 0, n-1);
    }
};

// Solution 1: Bottom Up DP

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n)));
        
        for(int r = m-1; r >= 0; r--) {
            for(int c1 = 0; c1 < n; c1++) {
                for(int c2 = 0; c2 < n; c2++) {
                    int res = grid[r][c1];
                    if(c1 != c2) {
                        res += grid[r][c2];
                    }
                    
                    if(r != m-1) {
                        int mx = 0;
                        for(int nc1 = c1-1; nc1 <= c1+1; nc1++) {
                            for(int nc2 = c2-1; nc2 <= c2+1; nc2++) {
                                if(nc1 >= 0 && nc1 < n && nc2 >= 0 && nc2 < n) {
                                    mx = max(mx, dp[r+1][nc1][nc2]);
                                }
                            }
                        }
                        res += mx;
                    }
                    dp[r][c1][c2] = res;
                }
            }
        }
        
        return dp[0][0][n-1];
    }
};