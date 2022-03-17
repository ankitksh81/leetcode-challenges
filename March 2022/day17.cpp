/*
	Score of Parentheses
	https://leetcode.com/problems/score-of-parentheses/
*/

// Solution 1: Divide and Conquer

class Solution {
public:
    int findScore(string &s, int i, int j) {
        int ans = 0, bal = 0;
        for(int k = i; k < j; k++) {
            bal += s[k] == '(' ? 1 : -1;
            if(bal == 0) {
                if(k - i == 1) {
                    ans++;
                }
                else {
                    ans += 2 * findScore(s, i+1, k);
                }
                i = k+1;
            }
        }
        
        return ans;
    }
    
    int scoreOfParentheses(string s) {
        return findScore(s, 0, s.length());
    }
};

// Solution 2: Stack

class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0);
        
        for (char c : s) {
            if (c == '(') {
                st.push(0);
            }
            else {
                int v = st.top();   st.pop();
                int w = st.top();   st.pop();
                st.push(w + max(2 * v, 1));
            }
        }
        
        return st.top();
    }
};

// Solution 2: Count Cores

class Solution {
public:
    int scoreOfParentheses(string s) {
        int ans = 0, bal = 0;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '(') {
                bal++;
            }
            else {
                bal--;
                if(s[i-1] == '(') {
                    ans += (1 << bal);
                }
            }
        }
        
        return ans;
    }
};