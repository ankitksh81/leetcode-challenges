// Problem link: https://leetcode.com/explore/challenge/card/september-leetcoding-challenge-2021/637/week-2-september-8th-september-14th/3974/


// Solution 1:

class Solution {
    bool isLetter(char c) {
        if(c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z') {
            return true;
        }
        return false;
    }
    
public:
    string reverseOnlyLetters(string s) {
        int n = s.length();
        int l = 0, r = n-1;
        
        while(l < r) {
            if(isLetter(s[l]) && isLetter(s[r])) {
                swap(s[l++], s[r--]);
            }
            else if(isLetter(s[l]) && !isLetter(s[r])) {
                r--;
            }
            else if(!isLetter(s[l]) && isLetter(s[r])) {
                l++;
            }
            else {
                l++;
                r--;
            }
        }
        return s;
    }
};