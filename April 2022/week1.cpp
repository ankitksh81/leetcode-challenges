/*
	Brace Expansion
	https://leetcode.com/problems/brace-expansion/
*/

// Solution: Backtracking

class Solution {
public:
    void getStrings(vector<string>& str, int i, string cur, vector<string>& ans) {
        if(i >= str.size()) {
            ans.push_back(cur);
            return;
        }
        
        string s = str[i];
        if(s[0] == '{') {
            for(char c : s) {
                if(c == ',' || c == '{' || c == '}') {
                    continue;
                }
                cur += c;
                getStrings(str, i + 1, cur, ans);
                cur.pop_back();
            }
        }
        else {
            cur += s;
            getStrings(str, i+1, cur, ans);
            cur.pop_back();
        }
    }
    
    vector<string> expand(string s) {
        vector<string> ans, strings;
        string cur = "";
        for(int i = 0; i < s.length(); i++) {
            cur += s[i];
            if(s[i] == '{' && cur != "") {
                cur.pop_back();
                strings.push_back(cur);
                cur = "{";
            }
            if(s[i] == '}') {
                strings.push_back(cur);
                cur = "";
            }
        }
        if(cur != "") {
            strings.push_back(cur);
        }
        
        getStrings(strings, 0,"", ans);
        sort(ans.begin(), ans.end());
        return ans;
    }
};