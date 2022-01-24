/*
	Detect Capital
	https://leetcode.com/problems/detect-capital/
*/

// Solution 1: Check all conditions

class Solution {
public:
    bool checkAllCaps(string &s) {
        bool flag = true;
        for(char &c: s) {
            flag = isupper(c);
            if(!flag) {
                break;
            }
        }
        return flag;
    }
    
    bool checkFirstCaps(string &s) {
        bool flag = (isupper(s[0]) ? true : false);
        for(int i = 1; i < s.length(); i++) {
            if(isupper(s[i])) {
                flag = false;
                break;
            }
        }
        return flag;
    }
    
    bool checkAllLower(string &s) {
        bool flag = true;
        for(char &c: s) {
            flag = islower(c);
            if(!flag) {
                break;
            }
        }
        return flag;
    }
    
    bool detectCapitalUse(string word) {
        return checkAllCaps(word) || checkAllLower(word) || checkFirstCaps(word);
    }
};

// Solution 2: Using flags

class Solution {
public:
    bool detectCapitalUse(string word) {
        bool flag = false, FLAG = false;
        for(int i = 1; i < word.length(); i++) {
            if(word[i] >= 'A' && word[i] <= 'Z') {
                FLAG = true;
            }
            if(word[i] >= 'a' && word[i] <= 'z') {
                flag = true;
            }
        }
        if(flag && FLAG) {
            return false;
        }
        if(FLAG && word[0] >= 'a' && word[0] <= 'z') {
            return false;
        }
        return true;
    }
};