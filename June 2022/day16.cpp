/*
	Longest Palindromic Substring
	https://leetcode.com/problems/longest-palindromic-substring/
*/

// Solution 1: Dynamic Programming

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if (n == 0) return "";
        
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        // all single characters are palindrome
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }
        
        int l = 0;
        int maxlen = 1;
        
        for (int i = n-1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                if (s[i] == s[j]) {
                    if (j - i == 1 || dp[i + 1][j - 1]) {
                        dp[i][j] = true;
                        
                        if (maxlen < j - i + 1) {
                            l = i;
                            maxlen = max(maxlen, j - i + 1);
                        }
                    }
                }
            }
        }
        
        return s.substr(l, maxlen);
    }
};


// Solution 2: Expand around the center

class Solution {
    pair<int, int> expand(string &s, int L, int R) {
        int l = L, r = R, last_l, last_r;
        
        while (l >= 0 && r < s.length() && (s[l] == s[r])) {
            last_l = l;
            last_r = r;
            l--;
            r++;
        }
        
        return {last_l, last_r};
    }
    
public:
    string longestPalindrome(string s) {
        string result = "";
        int N = s.length();
        
        for (int i = 0; i < N; i++) {
            pair<int, int> start = expand(s, i, i);
            pair<int, int> end = expand(s, i, i+1);
            
            pair<int, int> temp;
            if (start.second - start.first > end.second - end.first) {
                temp = start;
            }
            else {
                temp = end;
            }
            int l = temp.first, r = temp.second;
            int len = r - l + 1;
            if (len > result.length()) {
                result = s.substr(l, len);
            }
        }
        
        return result;
    }
};