/*
	Longest String Chain
	https://leetcode.com/problems/longest-string-chain/
*/

// Solution 1: Recursion + Memoization

class Solution {
    unordered_set<string> wSet;
    unordered_map<string, int> dp;
public:
    vector<string> getPossibleWords(string word) {
        vector<string> res;
        string cur = "";
        for (int i = 0; i < word.length(); i++) {
            cur = word.substr(0, i) + word.substr(i+1);
            res.push_back(cur);
        }
        
        return res;
    }
    
    int dfs(string word) {
        if (dp.find(word) != dp.end())  return dp[word];
        
        vector<string> newWords = getPossibleWords(word);
        int mx = 1;
        for (string newWord : newWords) {
            if (wSet.find(newWord) != wSet.end()) {
                mx = max(mx, 1 + dfs(newWord));
            }
        }
        
        return dp[word] = mx;
    }
    
    int longestStrChain(vector<string>& words) {
        for (string word : words) {
            wSet.insert(word);
        }
        
        int maxLength = 1;
        for (string word : words) {
            maxLength = max(maxLength, dfs(word));
        }
        
        return maxLength;
    }
};

// Solution 2: Dynamic Programming

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        unordered_set<string> wSet;
        unordered_map<string, int> dp;
        int maxLength = 1;
        
        sort(words.begin(), words.end(), [](string &a, string &b) {
            return a.length() < b.length();
        });
        for (string word : words) {
            wSet.insert(word);
        }
        
        for (const string &word : words) {
            int curLen = 1;
            for (int i = 0; i < word.length(); i++) {
                string predecessor = word.substr(0, i) + word.substr(i + 1);
                if (dp.find(predecessor) != dp.end()) {
                    int prevLen = dp[predecessor];
                    curLen = max(curLen, prevLen + 1);
                }
            }
            dp[word] = curLen;
            maxLength = max(maxLength, curLen);
        }
        
        return maxLength;
    }
};