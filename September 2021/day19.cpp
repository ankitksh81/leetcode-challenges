// Problem link: https://leetcode.com/explore/challenge/card/september-leetcoding-challenge-2021/638/week-3-september-15th-september-21st/3980/

// Solution:

class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.length(), m = t.length();
        if(n < m) {
            return 0;
        }
        if(n == m) {
            return s == t;
        }
        vector<vector<long long>> dp(m+1, vector<long long>(n+1));
        // initialize first col with 0 because if s is an empty string
        // then we cannot form t
        for(int i = 0; i <= m; i++) {
            dp[i][0] = 0;
        }
        
        // initialize first row with 1 because if t is an empty string
        // then we can form it with any string s
        for(int i = 0; i <= n; i++) {
            dp[0][i] = 1;
        }
        
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                // if the character at previous index is not same then value is same as
                // value without including that character
                if(t[i-1] != s[j-1]) {
                    dp[i][j] = dp[i][j-1];
                }
                
                // if the character at previous index is equal then value is sum of:
                // case 1: all substrings without the previous character in s
                // case 2: all substrings without the previous character in both s & t
                else {
                    dp[i][j] = dp[i][j-1] + dp[i-1][j-1];
                }
            }
        }
        // dp[m][n] = number of ways to make t of length m
        // from s of length n
        return dp[m][n];
    }
};