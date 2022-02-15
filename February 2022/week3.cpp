/*
	Find K-Length Substrings With No Repeated Characters
	https://leetcode.com/problems/find-k-length-substrings-with-no-repeated-characters/
*/

// Solution: Sliding Window

class Solution {
public:
    int numKLenSubstrNoRepeats(string s, int k) {
        if(s.length() < k) {
            return 0;
        }
        unordered_map<char, int> umap;
        int cnt = 0;
        for(int i = 0; i < k; i++) {
            umap[s[i]]++;
        }
        if(umap.size() == k) {
            cnt++;
        }
        
        int l = 0, r = k;
        while(r < s.length()) {
            umap[s[l]]--;
            if(umap[s[l]] == 0) {
                umap.erase(s[l]);
            }
            umap[s[r]]++;
            if(umap.size() == k) {
                cnt++;
            }
            l++;
            r++;
        }
        
        return cnt;
    }
};