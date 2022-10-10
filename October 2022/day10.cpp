/*
        Break a Palindrome
        https://leetcode.com/problems/break-a-palindrome/description/
*/

// Solution: Greedy

class Solution {
public:
    string breakPalindrome(string palindrome) {
        const int N = palindrome.length();
        if (N < 2) return "";

        for (int i = 0; i < N/2; i++) {
            if (palindrome[i] != 'a') {
                palindrome[i] = 'a';
                return palindrome;
            }
        }

        palindrome[N-1] = 'b';
        return palindrome;
    }
};
