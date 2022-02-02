/*
	Find All Anagrams in a String
	https://leetcode.com/problems/find-all-anagrams-in-a-string/
*/

// Solution: Sliding Window

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> hash1(26), hash2(26), result;
        if(p.length() > s.length()) {
            return result;
        }
        
        int left = 0, right = 0;
        while(right < p.length()) {
            hash2[p[right] - 'a']++;
            hash1[s[right] - 'a']++;
            right++;
        }
        
        right--;
        while(right < s.length()) {
            if(hash1 == hash2) {
                result.push_back(left);
            }
            right++;
            if(right != s.length()) {
                hash1[s[right] - 'a']++;
                hash1[s[left] - 'a']--;
            }
            left++;
        }
        return result;
    }
};