/*
    Decode String
    https://leetcode.com/problems/decode-string/
*/

// Solution:

class Solution {
public:
    string decode(string s, int &i) {
        string temp = "";
        while(i < s.length() && s[i] != ']') {
            if(!isdigit(s[i])) {
                temp += s[i++];
            }
            else {
                int num = 0;
                while(i < s.length() && isdigit(s[i])) {
                    num = num * 10 + (s[i++] - '0');
                }
                
                i++;
                string next = decode(s, i);
                i++;
                while(num--) {
                    temp += next;
                }
            }
        }
        return temp;
    }
    
    string decodeString(string s) {
        int i = 0;
        return decode(s, i);
    }
};