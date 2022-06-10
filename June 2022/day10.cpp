/*
	Longest Substring Without Repeating Characters
	https://leetcode.com/problems/longest-substring-without-repeating-characters/
*/

// Solution: Hashmap with Two Pointers

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_map<char, int> mp;
        
        int maxlen = 0, l = 0, r = 0;
        while (r < n) {
            if (mp.find(s[r]) != mp.end()) {
                l = max(l, mp[s[r]] + 1);
            }
            
            maxlen = max(maxlen, r - l + 1);
            mp[s[r]] = r;
            r++;
        }
        
        return maxlen;
    }
};