/*
	Unique Morse Code Words
	https://leetcode.com/problems/unique-morse-code-words/
*/

// Solution: Hashset

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> table = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.",
                "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.",
                "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
        
        unordered_set<string> vis;
        
        for (string &word : words) {
            string code = "";
            for (char &c : word) {
                code += table[c - 'a'];
            }
            vis.insert(code);
        }
        
        return vis.size();
    }
};