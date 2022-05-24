/*
	Longest Valid Parentheses
	https://leetcode.com/problems/longest-valid-parentheses/
*/

// Solution 1: Dynamic Programming

class Solution {
public:
    int longestValidParentheses(string s) {
        int result = 0;
        vector<int> dp(s.length());
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
                }
                else if (i - dp[i-1] > 0 && s[i - dp[i - 1] - 1] == '(') {
                    dp[i] = dp[i - 1] + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
                }
                
                result = max(result, dp[i]);
                
            }
        }
        
        return result;
    }
};

// Solution 2: Stack

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);
        
        int result = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push(i);
            }
            if (s[i] == ')') {
                if (!st.empty()) {
                    st.pop();
                }
                if (st.empty()) {
                    st.push(i);
                }
            }
            
            result = max(result, (i - st.top()));
        }
        
        return result;
    }
};