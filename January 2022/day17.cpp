/*
	Word Pattern
	https://leetcode.com/problems/word-pattern/
*/

// Solution: Hash Maps

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, int> mp1;
        unordered_map<string, int> mp2;
        
        istringstream ss(s);
        string word;
        int i = 0, n = pattern.length();
        
        for(word; ss >> word; i++) {
            if(i == n || mp1[pattern[i]] != mp2[word]) {
                return false;
            }
            mp1[pattern[i]] = mp2[word] = i+1;
        }
        return i == n;
    }
};