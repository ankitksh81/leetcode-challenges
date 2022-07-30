/*
	Word Subsets
	https://leetcode.com/problems/word-subsets/
*/

// Solution: Hashmap

class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> result;
        vector<int> freq(26), cur(26);
        for (string &s : words2) {
            for (char &c : s) {
                cur[c - 'a']++;
                if (freq[c - 'a'] < cur[c - 'a']) {
                    freq[c - 'a'] = cur[c - 'a'];
                }
            }
            fill(cur.begin(), cur.end(), 0);
        }
        
        for (string &s : words1) {
            fill(cur.begin(), cur.end(), 0);
            for (char &c : s) {
                cur[c - 'a']++;
            }
            bool ok = true;
            for (int i = 0; i < 26; i++) {
                if (freq[i] > 0 && (cur[i] < freq[i])) {
                    ok = false;
                    break;
                }
            }
            
            if (ok) result.push_back(s);
        }
        
        return result;
    }
};