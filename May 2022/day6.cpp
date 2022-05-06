/*
	Remove All Adjacent Duplicates in String II
	https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/
*/

// Solution 1: Storing Counts

class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<int> cnt(s.length());
        for(int i = 0; i < s.length(); i++) {
            if(i == 0 || s[i] != s[i-1]) {
                cnt[i] = 1;
            }
            else {
                cnt[i] = cnt[i-1] + 1;
                if(cnt[i] == k) {
                    s.erase(i - k + 1, k);
                    i = i - k;
                }
            }
        }
        
        return s;
    }
};

// Solution 2: Stack without Reconstruction

class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n = s.length();
        stack<int> cnt;
        
        for (int i = 0; i < s.length(); i++) {
            if (i == 0 || s[i] != s[i - 1]) {
                cnt.push(1);
            }
            else if (++cnt.top() == k) {
                cnt.pop();
                s.erase(i - k + 1, k);
                i = i - k;
            }
        }
        
        return s;
    }
};

// Solution 3: Stack with Reconstruction

class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n = s.length();
        vector<pair<int, char>> cnt;
        
        for (int i = 0; i < s.length(); i++) {
            if (cnt.empty() || s[i] != cnt.back().second) {
                cnt.push_back({1, s[i]});
            }
            else if (++cnt.back().first == k) {
                cnt.pop_back();
            }
        }
        
        s = "";
        for(auto &p : cnt) {
            for(int i = 0; i < p.first; i++) {
                s += p.second;
            }
        }
        
        return s;
    }
};

// Solution 4: Stack with string modification

class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n = s.length();
        int j = 0;
        stack<int> cnt;
        
        for (int i = 0; i < n; i++, j++) {
            s[j] = s[i];
            if (j == 0 || s[j] != s[j-1]) {
                cnt.push(1);
            }
            else if (++cnt.top() == k) {
                cnt.pop();
                j -= k;
            }
        }
        
        return s.substr(0, j);
    }
};