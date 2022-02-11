/*
	Permutation in String
	https://leetcode.com/problems/permutation-in-string/
*/

// Solution: Sliding Window

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()) {
            return false;
        }
        
        vector<int> s1map(26), s2map(26);
        for(int i = 0; i < s1.length(); i++) {
            s1map[s1[i] - 'a']++;
            s2map[s2[i] - 'a']++;
        }
        
        int cnt = 0;
        for(int i = 0; i < 26; i++) {
            if(s1map[i] == s2map[i]) {
                cnt++;
            }
        }
        
        for(int i = 0; i < s2.length() - s1.length(); i++) {
            int r = s2[i + s1.length()] - 'a';
            int l = s2[i] - 'a';
            if(cnt == 26) {
                return true;
            }
            s2map[r]++;
            if(s2map[r] == s1map[r]) {
                cnt++;
            }
            else if(s2map[r] == s1map[r] + 1) {
                cnt--;
            }
            s2map[l]--;
            if(s2map[l] == s1map[l]) {
                cnt++;
            }
            else if(s2map[l] == s1map[l] - 1) {
                cnt--;
            }
        }
        return cnt == 26;
    }
};