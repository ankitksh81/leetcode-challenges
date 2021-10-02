/*
    Dungeon Game
    https://leetcode.com/problems/dungeon-game/
*/

// Solution 1:

class Solution {
    int m, n;
    int dp[205][205];
public:
    int solve(vector<vector<int>>& dungeon, int i, int j) {
        if(i == m-1 && j == n-1) {
            return dp[i][j] = (dungeon[i][j] <= 0 ? -dungeon[i][j] + 1 : 1);
        }
        
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        
        int right_path = INT_MAX, down_path = INT_MAX;
        if(i + 1 < m) {
            down_path = solve(dungeon, i + 1, j);
        }
        if(j + 1 < n) {
            right_path = solve(dungeon, i, j + 1);
        }
        
        int health_req = min(right_path, down_path) - dungeon[i][j];
        
        return dp[i][j] = (health_req <= 0 ? 1 : health_req);
    }
    
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        m = dungeon.size();
        n = dungeon[0].size();
        memset(dp, -1, sizeof(dp));
        
        int ans = solve(dungeon, 0, 0);
        return ans;
    }
};


// Solution 2:

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, INT_MAX));
        
        // Smallest Subproblem
        dp[m-1][n-1] = max(1, 1 - dungeon[m-1][n-1]);
        
        // Top to Bottom ; Left to Right
        for(int i = m-1 ; i >= 0 ; i--){
            for(int j = n-1 ; j >= 0 ; j--){
                if(i == m-1 && j == n-1) {
                    continue;
                }
                
                if(i+1 < m) {
                    dp[i][j] = min(dp[i][j], max(1, dp[i+1][j] - dungeon[i][j]));
                }
                if(j+1 < n) {
                    dp[i][j] = min(dp[i][j], max(1, dp[i][j+1] - dungeon[i][j]));
                }
            }
        }
        
        return dp[0][0];
    }
};