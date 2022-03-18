/*
	Remove Duplicate Letters
	https://leetcode.com/problems/remove-duplicate-letters/
*/

// Solution: Monotonic Stack & Greedy

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> idx(26, 0);
        vector<bool> seen(26, false);
        
        for(int i = 0; i < s.length(); i++) {
            idx[s[i] - 'a'] = i;
        }
        
        stack<char> st;
        for(int i = 0; i < s.length(); i++) {
            while(!st.empty() && st.top() > s[i] && !seen[s[i] - 'a'] && idx[st.top() - 'a'] > i) {
                seen[st.top() - 'a'] = false;
                st.pop();
            }
            if(!seen[s[i] - 'a']) {
                seen[s[i] - 'a'] = true;
                st.push(s[i]);
            }
        }
        
        string ans = "";
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};