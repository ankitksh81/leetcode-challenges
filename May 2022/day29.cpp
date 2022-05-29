/*
	Maximum Product of Word Lengths
	https://leetcode.com/problems/maximum-product-of-word-lengths/
*/

// Solution 1: Using bitset as Hashmap

class Solution {
public:
    bool checkCommon(bitset<26>& a, bitset<26>& b) {
        for (int i = 0; i < 26; i++) {
            if (a[i] && b[i])   return true;
        }
        
        return false;
    }
    
    int maxProduct(vector<string>& words) {
        int N = words.size();
        int ans = 0;
        vector<bitset<26>> chars(N);
        
        for (int i = 0; i < N; i++) {
            for (auto &ch : words[i])   chars[i][ch - 'a'] = 1;
            
            for (int j = 0; j < i; j++) {
                if (!checkCommon(chars[i], chars[j])) {
                    ans = max(ans, int(words[i].size() * words[j].size()));
                }
            }
        }
        
        return ans;
    }
};

// Solution 2: Using bitsets & Comparing Hash values

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int N = words.size(), ans = 0;
        vector<int> mask(N);
        
        for (int i = 0; i < N; i++) {
            for (auto &ch : words[i]) {
                mask[i] |= 1 << (ch - 'a');
            }
            
            for (int j = 0; j < i; j++) {
                if ((mask[i] & mask[j]) == 0) {
                    ans = max(ans, int(words[i].size() * words[j].size()));
                }
            }
        }
        
        return ans;
    }
};