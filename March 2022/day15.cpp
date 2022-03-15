/*
	Minimum Remove to Make Valid Parentheses
	https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/
*/

// Solution: Stack

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '(') {
                st.push(i);
            }
            if(s[i] == ')') {
                if(!st.empty()) {
                    st.pop();
                }
                else {
                    s[i] = '*';
                }
            }
        }
        
        while(!st.empty()) {
            s[st.top()] = '*';
            st.pop();
        }
        
        string res = "";
        for(char c : s) {
            if(c != '*') {
                res += c;
            }
        }
        
        return res;
    }
};