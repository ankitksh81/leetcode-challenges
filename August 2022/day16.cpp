/*
	First Unique Character in a String
	https://leetcode.com/problems/first-unique-character-in-a-string/
*/

// Solution: Hashmap

class Solution {
public:
    int firstUniqChar(string s) {
        int freq[26] = {};
        for (char &c : s) {
            freq[c - 'a']++;
        }
        
        for (int i = 0; i < s.length(); i++) {
            if (freq[s[i] - 'a'] == 1) return i;
        }
        
        return -1;
    }
};