/*
	Minimum Window Substring
	https://leetcode.com/problems/minimum-window-substring/
*/

class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.length(), n = t.length();
        if(m == 0 || n == 0) {
            return "";
        }
        
        vector<int> freq(128);
        int req = n;
        for(int i = 0; i < n; i++) {
            freq[t[i]]++;
        }
        
        int min = INT_MAX, l = 0, r = 0, left = 0;
        while(r <= m and l < m) {
            if(req > 0) {
                if(r == m) {
                    break;
                }
                
                freq[s[r]]--;
                if(freq[s[r]] >= 0) {
                    req--;
                }
                
                r++;
            }
            else {
                if(r - l < min) {
                    min = r - l;
                    left = l;
                }
                freq[s[l]]++;
                if(freq[s[l]] > 0) {
                    req++;
                }
                
                l++;
            }
        }
        
        return min == INT_MAX ? "" : s.substr(left, min);
    }
};