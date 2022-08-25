/*
	Ransom Note
	https://leetcode.com/problems/ransom-note/
*/

// Solution: Greedy

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> cnt1(26, 0), cnt2(26, 0);
        for (char c : ransomNote) cnt1[c - 'a']++;
        for (char c : magazine) cnt2[c - 'a']++;
        
        for (int i = 0; i < 26; i++) {
            if (cnt1[i] > cnt2[i]) return false;
        }
        
        return true;
    }
};