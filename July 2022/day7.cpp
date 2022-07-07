/*
	Interleaving String
	https://leetcode.com/problems/interleaving-string/
*/

// Solution 1: Recursion

class Solution {
public:
    class Solution {
public:
    bool solve(string &s1, string &s2, string &s3, int n, int m, int l) {
        if (n < 0 && m < 0 && l < 0) return true;
        
        if (n >= 0 && s1[n] == s3[l] && m >= 0 && s2[m] == s3[l]) {
            return solve(s1, s2, s3, n-1, m, l-1) || solve(s1, s2, s3, n, m-1, l-1);
        }
        
        if (n >= 0 && s1[n] == s3[l]) {
            return solve(s1, s2, s3, n-1, m, l-1);
        }
        if (m >= 0 && s2[m] == s3[l]) {
            return solve(s1, s2, s3, n, m-1, l-1);
        }
        
        return false;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.length(), m = s2.length();
        if (n + m != s3.length()) {
            return false;
        }
        return solve(s1, s2, s3, n-1, m-1, s3.length()-1);
    }
};
};


// Solution 2: Recursion + Memoization

class Solution {
    int dp[105][105];
public:
    bool solve(string &s1, string &s2, string &s3, int n, int m, int l) {
        if (n < 0 && m < 0 && l < 0) return true;
        
        if (n >= 0 && m >= 0 && dp[n][m] != -1) return dp[n][m];
        
        if (n >= 0 && s1[n] == s3[l] && m >= 0 && s2[m] == s3[l]) {
            return dp[n][m] = solve(s1, s2, s3, n-1, m, l-1) || solve(s1, s2, s3, n, m-1, l-1);
        }
        
        if (n >= 0 && s1[n] == s3[l]) {
            return solve(s1, s2, s3, n-1, m, l-1);
        }
        if (m >= 0 && s2[m] == s3[l]) {
             return solve(s1, s2, s3, n, m-1, l-1);
        }
        
        return false;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.length(), m = s2.length();
        if (n + m != s3.length()) {
            return false;
        }
        memset(dp, -1, sizeof(dp));
        return solve(s1, s2, s3, n-1, m-1, s3.length()-1);
    }
};


// Solution 3: Dynamic Programming

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.length(), m = s2.length(), p = s3.length();
        if (n + m != p) return false;
        
        vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));
        
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                if (i == 0 && j == 0) {
                    dp[i][j] = true;
                }
                else if (i == 0) {
                    if (s2[j-1] == s3[j-1]) {
                        dp[i][j] = dp[i][j-1];
                    }
                }
                else if (j == 0) {
                    if (s1[i-1] == s3[i-1]) {
                        dp[i][j] = dp[i-1][j];
                    }
                }
                else if (s1[i-1] == s3[i+j-1] && s2[j-1] != s3[i+j-1]) {
                    dp[i][j] = dp[i-1][j];
                }
                else if (s1[i-1] != s3[i+j-1] && s2[j-1] == s3[i+j-1]) {
                    dp[i][j] = dp[i][j-1];
                }
                else if (s1[i-1] == s3[i+j-1] && s2[j-1] == s3[i+j-1]) {
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                }
            }
        }
        
        return dp[n][m];
    }
};