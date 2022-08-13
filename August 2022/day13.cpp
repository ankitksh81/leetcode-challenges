/*
	Substring with Concatenation of All Words
	https://leetcode.com/problems/substring-with-concatenation-of-all-words/solution/
*/

// Solution 1: Check All Indices using HashMap

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.length(), m = words.size(), l = words[0].length();
        unordered_map<string, int> freq, subFreq;
        vector<int> ans;
        
        for(string word : words) {
            freq[word]++;
        }
        
        int left;
        for(int i = 0; i + m * l <= n; i++) {
            for(int j = i; j < i + l * m; j += l) {
                string cur = s.substr(j, l);
                if(freq.find(cur) != freq.end()) {
                    subFreq[cur]++;
                }
            }
            
            if(freq == subFreq) {
                ans.push_back(i);
            }
            
            subFreq.clear();
        }
        
        return ans;
    }
};


// Solution 2: Sliding Window

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int len = words[0].size(), n = words.size(), ssize = s.size(), left, found;
        vector<int> res;
        
        unordered_map<string, int> freq, tmp;
        for (auto word : words) freq[word]++;
            
        for (int i = 0; i < len; i++) {
            tmp.clear();
            left = i, found = 0;
            
            for (int j = i; j <= ssize - len; j += len) {
                string curr = s.substr(j, len);
                
                if (freq.find(curr) != freq.end()) {
                    tmp[curr]++;
                    found++;

                    while (freq[curr] < tmp[curr]) {
                        tmp[s.substr(left, len)]--;
                        found--;
                        left += len;
                    }

                    if (found == n) res.push_back(left);
                }
                
                else {
                    tmp.clear();
                    found = 0;
                    left = j + len;
                }
            }
        }
        return res;
    }
};