/*
    Palindrome Partitioning
    https://leetcode.com/problems/palindrome-partitioning/
*/

// Solution 1: Backtracking

class Solution {
    vector<vector<string>> result;
public:
    bool isPalindrome(string &s, int l, int h) {
        while(l < h) {
            if(s[l++] != s[h--]) {
                return false;
            }
        }
        return true;
    }
    
    void findPalindromes(string &s, int start, vector<string>& curList) {
        if(start >= s.length()) {
            result.push_back(curList);
        }
        
        for(int end = start; end < s.length(); end++) {
            if(isPalindrome(s, start, end)) {
                curList.push_back(s.substr(start, end - start + 1));
                findPalindromes(s, end + 1, curList);
                curList.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<string> curList;
        findPalindromes(s, 0, curList);
        return result;
    }
};

// Solution 2: Backtracking + DP

class Solution {
    vector<vector<string>> result;
    vector<vector<bool>> dp;
public:
    void findPalindromes(string &s, int start, vector<string>& curList) {
        if(start >= s.length()) {
            result.push_back(curList);
        }
        
        for(int end = start; end < s.length(); end++) {
            if(s[start] == s[end] && (end - start <= 2 || dp[start+1][end-1])) {
                dp[start][end] = true;
                curList.push_back(s.substr(start, end - start + 1));
                findPalindromes(s, end + 1, curList);
                curList.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        dp.assign(s.length(), vector<bool>(s.length(), false));
        vector<string> curList;
        findPalindromes(s, 0, curList);
        return result;
    }
};