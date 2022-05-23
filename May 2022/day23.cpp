/*
	Ones and Zeros
	https://leetcode.com/problems/ones-and-zeroes/
*/

// Solution 1: Recursion with Memoization

class Solution {
    int dp[605][105][105];
public:
    vector<int> count(string s) {
        vector<int> v(2);
        for (char c : s) {
            v[c - '0']++;
        }
        
        return v;
    }
    
    int solve(vector<string>& strs, int i, int m, int n) {
        if (i == strs.size()) {
            return 0;
        }
        
        if (dp[i][m][n] != -1) {
            return dp[i][m][n];
        }
        
        vector<int> cnt = count(strs[i]);
        int  taken = -1;
        if (m - cnt[0] >= 0 && n - cnt[1] >= 0) {
            taken = solve(strs, i+1, m - cnt[0], n - cnt[1]) + 1;
        }
        int not_taken = solve(strs, i+1, m, n);
        return dp[i][m][n] = max(taken, not_taken);
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        memset(dp, -1, sizeof(dp));
        return solve(strs, 0, m, n);
    }
};

// Solution 2: Dynamic Programming

class Solution {
    vector<int> count(string &s) {
        vector<int> res(2);
        for (char &c : s) {
            res[c - '0']++;
        }
        
        return res;
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (string s : strs) {
            vector<int> cnt = count(s);
            for (int i = m; i >= cnt[0]; i--) {
                for (int j = n; j >= cnt[1]; j--) {
                    dp[i][j] = max(1 + dp[i - cnt[0]][j - cnt[1]], dp[i][j]);
                }
            }
        }
        
        return dp[m][n];
    }
};