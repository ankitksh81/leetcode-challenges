/*
        Count and Say
        https://leetcode.com/problems/count-and-say/description/
*/

// Solution: Recursion

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";

        string s = countAndSay(n-1);
        int cnt = 1;

        string t = "";
        for (int i = 1; i <= s.length(); i++) {
            if (i == s.length()) {
                t += to_string(cnt) + s[i-1];
                break;
            }
            if (s[i-1] == s[i]) {
                cnt++;
            }
            else {
                t += to_string(cnt) + s[i-1];
                cnt = 1;
            }
        }

        return t;
    }
};
