/*
	Check If a String Contains All Binary Codes of Size K
	https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/
*/

// Solution 1: Using Hash Set

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if (k > s.length()) {
            return false;
        }
        
        unordered_set<string> seen;
        for (int i = 0; i <= s.length()-k; i++) {
            seen.insert(s.substr(i, k));
        }
        
        return seen.size() == (1 << k);
    }
};

// Solution 2: Using Rolling Hash

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.length(), size = 1 << k;
        int count = 0, hash = 0, allOnes = ~size;
        
        vector<bool> set(size, false);
        
        for (int i = 0; i < n; i++) {
            hash = ((hash << 1) & allOnes) | (s[i] - '0');
            if (i >= k - 1 && !set[hash]) {
                set[hash] = true;
                count++;
            }
        }
        
        return count == size;
    }
};