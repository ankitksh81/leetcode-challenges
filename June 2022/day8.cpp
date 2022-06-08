/*
	Remove Palindromic Subsequences
	https://leetcode.com/problems/remove-palindromic-subsequences/
*/

// Solution 1: Check Palindrome

class Solution {
    bool isPalindrome(string &s) {
        int l = 0, r = s.length()-1;
        while (l < r) {
            if (s[l++] != s[r--])   return false;
        }
        
        return true;
    }
public:
    int removePalindromeSub(string s) {
        return isPalindrome(s) ? 1 : 2;
    }
};