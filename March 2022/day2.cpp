/*
	Is Subsequence
	https://leetcode.com/problems/is-subsequence/
*/

// Solution: Two Pointers

class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.empty()) {
            return true;
        }
        int l = 0, r = 0;
        bool flag = false;
        for(r; r < t.length(); r++) {
            if(s[l] == t[r]) {
                l++;
            }
            if(l > s.length()-1) {
                flag = true;
                break;
            }
        }
        return flag;
    }
};