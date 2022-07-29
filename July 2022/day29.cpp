/*
	Find and Replace Pattern
	https://leetcode.com/problems/find-and-replace-pattern/
*/

// Solution 1: Hashmap

class Solution {
public:
    string getGroups(string &s) {
        unordered_map<char, int> mp;
        string res = "";
        for (char c : s) {
            if (mp.find(c) == mp.end()) {
                mp[c] = mp.size();
            }
        }
        for (int i = 0; i < s.length(); i++) {
            res += (mp[s[i]] + 'a');
        }
        return res;
    }
    
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> result;
        
        string patternGroup = getGroups(pattern);
        for (string word : words) {
            if (patternGroup == getGroups(word)) {
                result.push_back(word);
            }
        }
        
        return result;
    }
};