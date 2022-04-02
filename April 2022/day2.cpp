/*
	Valid Palindrome II
	https://leetcode.com/problems/valid-palindrome-ii/
*/

// Solution: Two Pointers

class Solution {
public:
    inline bool check(string &s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    
    bool validPalindrome(string s) {
        int l = 0, r = s.length()-1;
        bool used = false;
        
        while (l < r) {
            if (s[l] != s[r]) {
                return check(s, l+1, r) || check(s, l, r-1);
            }
            l++;
            r--;
        }
        
        return true;
    }
};