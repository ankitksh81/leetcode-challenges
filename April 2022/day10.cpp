/*
	Baseball Game
	https://leetcode.com/problems/baseball-game/
*/

// Solution: Stack

class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> st;
        for(string s : ops) {
            if(s == "C") {
                st.pop();
            }
            else if(s == "+") {
                int op1 = st.top(); st.pop();
                int op2 = st.top();
                st.push(op1);
                st.push(op1 + op2);
            }
            else  if(s == "D") {
                int op = st.top();
                st.push(2 * op);
            }
            else {
                st.push(stoi(s));
            }
        }
        
        int ans = 0;
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }
        
        return ans;
    }
};