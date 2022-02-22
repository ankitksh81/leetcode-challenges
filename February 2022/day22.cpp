/*
	Excel Sheet Column Number
	https://leetcode.com/problems/excel-sheet-column-number/
*/

// Solution 1: Right to Left Traversal

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int res = 0;
        unordered_map<char, int> umap;
        for(int i = 0; i < 26; i++) {
            int c = i + 65;
            umap[(char)c] = i + 1;
        }
        
        int n = columnTitle.length();
        for(int i = 0; i < n; i++) {
            char cur_char = columnTitle[n - i - 1];
            res += umap[cur_char] * pow(26, i);
        }
        
        return res;
    }
};

// Solution 2: Left to Right

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int res = 0;
        int n = columnTitle.length();
        
        for(int i = 0; i < n; i++) {
            res = res * 26;
            res += columnTitle[i] - 'A' + 1;
        }
        
        return res;
    }
};