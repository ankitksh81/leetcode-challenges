/*
    Maximal square
    https://leetcode.com/problems/maximal-square/
*/

// Solution 1:

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        
        int maxSqLen = 0;
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(matrix[i-1][j-1] == '1') {
                    dp[i][j] = min({dp[i][j-1], dp[i-1][j], dp[i-1][j-1]}) + 1;
                    maxSqLen = max(maxSqLen, dp[i][j]);
                }
            }
        }
        
        return maxSqLen * maxSqLen;
    }
};

// Solution 2:

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> dp(n+1);
        
        int maxSqLen = 0, prev = 0;
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                int temp = dp[j];
                if(matrix[i-1][j-1] == '1') {
                    dp[j] = min({dp[j-1], prev, dp[j]}) + 1;
                    maxSqLen = max(maxSqLen, dp[j]);
                }
                else {
                    dp[j] = 0;
                }
                prev = temp;
            }
        }
        
        return maxSqLen * maxSqLen;
    }
};