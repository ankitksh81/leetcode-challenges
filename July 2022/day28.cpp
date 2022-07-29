/*
	Valid Anagram
	https://leetcode.com/problems/valid-anagram/
*/

// Solution 1: Sorting

class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(begin(s), end(s));
        sort(begin(t), end(t));
        return s == t;
    }
};


// Solution 2: Counting Frequencies

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> cnt1(26), cnt2(26);
        for (char c : s) {
            cnt1[c - 'a']++;
        }
        for (char c : t) {
            cnt2[c - 'a']++;
        }
        
        for(int i = 0; i < 26; i++) {
            if (cnt1[i] !=  cnt2[i])
                return false;
        }
        
        return true;
    }
};