/*
	Simplify Path\
	https://leetcode.com/problems/simplify-path/
*/

// Solution: Stack

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string str;
        stringstream ss(path);
        while(getline(ss, str, '/')) {
            if(str == "." || str == "") {
                continue;
            }
            if(str == "..") {
                if(!st.empty()) {
                    st.pop();
                }
            }
            else {
                st.push(str);
            }
        }
        
        vector<string> v;
        while(!st.empty()) {
            v.push_back(st.top());
            st.pop();
        }
        reverse(v.begin(), v.end());
        string ans = "/";
        for(string s : v) {
            ans += s;
            ans += "/";
        }
        ans.pop_back();
        
        return ans == "" ? "/" : ans;
    }
};