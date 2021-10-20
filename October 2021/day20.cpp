/*
    Reverse words in a string
    https://leetcode.com/problems/reverse-words-in-a-string/
*/

// Solution:

class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        int n = s.length();
        int i = n-1;
        while(i >= 0) {
            string temp = "";
            while(i >= 0 && s[i] != ' ') {
                temp = s[i] + temp;
                i--;
            }
            if(temp != "") {
                ans += temp + " ";
            }
            i--;
        }
        if(ans.back() == ' ') {
            ans.pop_back();
        }
        return ans;
    }
};