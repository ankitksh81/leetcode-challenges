/*
	Group Shifted Strings
	https://leetcode.com/problems/group-shifted-strings/
*/

// Solution:

class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> mp;
        for(auto &str: strings) {
            string res = "";
            for(char &c: str) {
                res += (c + 26 - str[0]) % 26 + 'a';
            }
            
            mp[res].push_back(str);
        }
        
        vector<vector<string>> groups;
        for(auto &[str, seq]: mp) {
            groups.push_back(seq);
        }
        
        return groups;
    }
};