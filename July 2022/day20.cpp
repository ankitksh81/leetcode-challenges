/*
	Number of Matching Subsequences
	https://leetcode.com/problems/number-of-matching-subsequences/
*/

// Solution 1: Check subsequence

class Solution {
public:
    bool isSubsequence(string &str, string &t) {
        int i = 0, j = 0;
        for (; j < t.length(); j++) {
            if (str[i] == t[j]) {
                i++;
            }
            
            if (i >= str.length()) {
                return true;
            }
        }
        
        return false;
    }
    
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<string, int> mp;
        for (string str : words) {
            mp[str]++;
        }
        
        int res = 0;
        for (auto it : mp) {
            int num = it.second;
            string str = it.first;
            if (isSubsequence(str, s)) {
                res += num;
            }
        }
        
        return res;
    }
};


// Solution 2: String find character

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int count = 0;
        size_t pos;
        
        if (s.empty()) {
            return 0;
        }
        
        for (const string& w : words) {
            if (w.empty()) continue;
            
            pos = 0;
            for (char c : w) {
                pos = s.find(c, pos);
                if (pos == string::npos) {
                    break;
                }
                pos++;
            }
            
            if (pos != string::npos) {
                count++;
            }
        }
        
        return count;
    }
};


// Solution 3: Moving character Pointers

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<const char*> waiting[128];
        for (auto &w : words) {
            waiting[w[0]].push_back(w.c_str());
        }
        
        for (char c : s) {
            auto adv = waiting[c];
            waiting[c].clear();
            for (auto it : adv) {
                waiting[*++it].push_back(it);
            }
        }
        
        return waiting[0].size();
    }
};