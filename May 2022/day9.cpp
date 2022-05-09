/*
	Letter COmbinations of a Phone Number
	https://leetcode.com/problems/letter-combinations-of-a-phone-number/
*/

// Solution: Backtracking

class Solution {
    vector<string> result;
    void getLetterCombinations(string &digits, int idx, string &cur, vector<string>& str) {
        if (idx == digits.length()) {
            result.push_back(cur);
            return;
        }
        
        int i = digits[idx] - '0';
        string curStr = str[i];
        for(char c : curStr) {
            cur += c;
            getLetterCombinations(digits, idx + 1, cur, str);
            cur.pop_back();
        }
    }
    
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }
        vector<string> str = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string cur;
        
        getLetterCombinations(digits, 0, cur, str);
        return result;
    }
};