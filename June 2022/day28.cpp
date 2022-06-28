/*
	Minimum Deletions to Make Character Frequencies Unique
	https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/
*/

// Solution 1: Greedy + Hashset

class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }
        
        int res = 0;
        unordered_set<int> seenFreq;
        
        for (int i = 0; i < 26; i++) {
            while (freq[i] && seenFreq.find(freq[i]) != seenFreq.end()) {
                freq[i]--;
                res++;
            }
            seenFreq.insert(freq[i]);
        }
        
        return res;
    }
};


// Solution 2: Sorting

class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }
        
        sort(freq.rbegin(), freq.rend());
        int res = 0, maxFreqAllowed = s.length();
        
        for (int i = 0; i < 26 && freq[i] > 0; i++) {
            if (freq[i] > maxFreqAllowed) {
                res += freq[i] - maxFreqAllowed;
                freq[i] = maxFreqAllowed;
            }
            maxFreqAllowed = max(0, freq[i] - 1);
        }
        
        return res;
    }
};