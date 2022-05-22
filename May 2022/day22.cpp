/*
	Palindromic Substrings
	https://leetcode.com/problems/palindromic-substrings/	
*/

// Solution 1: Dynamic Programming

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        if (n <= 0) {
            return 0;
        }
        
        int res = n;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }
        
        for (int i = 0; i < n-1; i++) {
            dp[i][i+1] = (s[i] == s[i+1]);
            res += dp[i][i+1];
        }
        
        for (int len = 3; len <= n; len++) {
            int i = 0;
            for (int j = i + len - 1; j < n; j++) {
                dp[i][j] = dp[i+1][j-1] && (s[i] == s[j]);
                res += dp[i][j];
                i++;
            }
        }
        
        return res;
    }
};

// Solution 2: Expand Around Possible Centers

class Solution {
    int countPalindromes(const string &s , int l, int h) {
        int res = 0;
        while (l >= 0 && h < s.length()) {
            if (s[l] != s[h]) {
                break;
            }
            l--;
            h++;
            
            res++;
        }
        
        return res;
    }
    
public:
    int countSubstrings(string s) {
        int n = s.length();
        int res = 0;
        
        for (int i = 0; i < n; i++) {
            res += countPalindromes(s, i, i);
            res += countPalindromes(s, i, i + 1);
        }
        
        return res;
    }
};