/*
	Delete Operation for Two Strings
	https://leetcode.com/problems/delete-operation-for-two-strings/
*/

// Solution 1: Recursion + Memoization (LCS Pattern)

class Solution {
    int dp[505][505];
public:
    int lcs(string &word1, string &word2, int n, int m) {
        if(n < 0 || m < 0) {
            return 0;
        }
        
        if(dp[n][m] != -1) {
            return dp[n][m];
        }
        
        if(word1[n] == word2[m]) {
            return dp[n][m] = 1 + lcs(word1, word2, n-1, m-1);
        }
        
        return dp[n][m] = max(lcs(word1, word2, n-1, m), lcs(word1, word2, n, m-1));
    }
    
    int findLCS(string &word1, string &word2) {
        memset(dp, -1, sizeof(dp));
        return lcs(word1, word2, word1.size()-1, word2.size()-1);
    }
    
    int minDistance(string word1, string word2) {
        int n = word1.length(), m = word2.length();
        int lcs = findLCS(word1, word2);
        if(lcs == 0) {
            return n + m;
        }
        return (n + m - 2 * lcs);
    }
};


// Solution 2: Dynamic Programming (LCS Pattern)

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length(), m = word2.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1));
        
        for (int i = 0; i <= n; i++)    dp[i][0] = i;
        for (int j = 0; j <= m; j++)    dp[0][j] = j;
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                }
                else {
                    dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        return dp[n][m];
    }
}; 