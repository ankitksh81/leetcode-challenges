/*
        Longest Substring with At Most Two Distinct Characters
        https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/
*/

// Solution: Hashmap

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int size = s.length();
        if(size < 3) {
            return size;
        }
        
        int res = 2, l = 0, r = 0;
        unordered_map<char, int> freq;
        
        while(r < size) {
            freq[s[r]] = r;
            r++;
            
            if(freq.size() == 3) {
                int idx = INT_MAX;
                for(auto ele : freq) {
                    idx = min(idx, ele.second);
                }
                freq.erase(s[idx]);
                l = idx + 1;
            }
            
            res = max(res, r - l);
        }
        
        return res;
    }
};
