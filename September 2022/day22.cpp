/*
        Reverse Words in a String III
        https://leetcode.com/problems/reverse-words-in-a-string-iii/
*/

// Solution: 

class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string res = "", temp;
        
        while (getline(ss, temp, ' ')) {
            reverse(temp.begin(), temp.end());
            res += temp + " ";
        }
        
        res.pop_back();
        return res;
    }
};
