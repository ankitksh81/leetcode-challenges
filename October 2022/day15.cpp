/*
	String Compression II
	https://leetcode.com/problems/string-compression-ii/
*/

// Solution 1: Recursion + Memoization

class Solution {
    inline int numDigits(const int num) {
        return (num == 1  ? 0 : num < 10 ? 1 : num < 100 ? 2 : 3);
    }
    
    int dp[102][102];
public:
    int solve(string s, int idx, int K, const int N) {
        int k = K;
        
        if (idx >= N || N - idx <= k) return 0;
        
        if (dp[idx][k] != -1) return dp[idx][k];
        
        int res = k ? solve(s, idx + 1, k - 1, N) : 1e8, c = 1;
        
        for (int i = idx + 1; i <= N; i++) {
            res = min(res, solve(s, i, k, N) + 1 + numDigits(c));
            
            if (i == N) break;
            if (s[i] == s[idx]) c++;
            else if (--k < 0) break;
        }
        
        return dp[idx][K] = res;
    }
    
    int getLengthOfOptimalCompression(string s, int k) {
        memset(dp, -1, sizeof(dp));
        return solve(s, 0, k, s.length());
    }
};


// Solution 2: Dynamic Programming

class Solution {
public:
    int getLengthOfOptimalCompression(string s, int K) {
        auto getDigits = [](int x) {
            return (x == 1 ? 1 : x < 10 ? 2 : x < 100 ? 3 : 4);
        };
        
        const int N = s.length();
        vector<vector<int>> dp(N+1, vector<int>(K+1, INT_MAX >> 1));
        dp[0][0] = 0;
        
        for (int i = 1; i <= N; i++) {
            for (int j = 0; j <= K && j <= i; j++) {
                if (j > 0) {
                    dp[i][j] = dp[i-1][j-1];
                }
                
                int same = 0, diff = 0;
                for (int idx = i; idx >= 1 && diff <= j; --idx) {
                    if (s[idx - 1] == s[i-1]) {
                        ++same;
                        dp[i][j] = min(dp[i][j], dp[idx-1][j-diff] + getDigits(same));
                    }
                    else {
                        ++diff;
                    }
                }
            }
        }
        
        return dp[N][K];
    }
};