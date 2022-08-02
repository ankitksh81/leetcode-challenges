/*
	Unique Paths
	https://leetcode.com/problems/unique-paths/
*/

// Solution 1: Dynamic Programming

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            dp[i][0] = 1;
        }
        for (int i = 0; i < n; i++) {
            dp[0][i] = 1;
        }
        
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        
        return dp[m-1][n-1];
    }
};


// Solution 2: Maths

class Solution {
public:
    int uniquePaths(int m, int n) {
        int N = m + n - 2;
        int r = m - 1;
        double res = 1;
        
        for(int i = 1; i <= r; i++) {
            res = res * (N - r + i) / i;
        }
        return (int)res;
    }
};