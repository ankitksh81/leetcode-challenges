/*
	Count Sorted Vowel Strings
	https://leetcode.com/problems/count-sorted-vowel-strings/
*/

// Solution 1: Recursion

class Solution {
    vector<string> vowels = {"a", "e", "i", "o", "u"};
public:
    int getCount(int n, int prev) {
        if (n == 0) {
            return 1;
        }
        
        int total = 0;
        for (int i = 0; i < vowels.size(); i++) {
            if (vowels[prev] <= vowels[i]) {
                total += getCount(n-1, i);
            }
        }
        
        return total;
    }
    
    int countVowelStrings(int n) {
        int result = 0;
        for (int i = 0; i < 5; i++) {
            result += getCount(n-1, i);
        }
        
        return result;
    }
};

// Solution 2: Dynamic Programming

class Solution {
    vector<string> vowels = {"a", "e", "i", "o", "u"};
    int dp[55][55];
public:
    int getCount(int n, int prev) {
        if (n == 0) {
            return 1;
        }
        
        if (dp[n][prev] != -1) {
            return dp[n][prev];
        }
        
        int total = 0;
        for (int i = 0; i < vowels.size(); i++) {
            if (vowels[prev] <= vowels[i]) {
                total += getCount(n-1, i);
            }
        }
        
        return dp[n][prev] = total;
    }
    
    int countVowelStrings(int n) {
        int result = 0;
        memset(dp, -1, sizeof(dp));
        
        for (int i = 0; i < 5; i++) {
            result += getCount(n-1, i);
        }
        
        return result;
    }
};