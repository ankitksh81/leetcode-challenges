/*
        Check if the Sentence is Pangram
        https://leetcode.com/problems/check-if-the-sentence-is-pangram/description/
*/

// Solution: Hashset

class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_set<char> charSet;

        for (char c : sentence) {
            charSet.insert(c);
        }

        return charSet.size() == 26;
    }
};
