/*
	Bag of Tokens
	https://leetcode.com/problems/bag-of-tokens/
*/

// Solution: Greedy

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int res = 0, cur = 0;
        int l = 0, r = tokens.size()-1;
        
        while (l <= r && (power >= tokens[l] || cur > 0)) {
            while (l <= r && power >= tokens[l]) {
                power -= tokens[l++];
                cur++;
            }
            
            res = max(res, cur);
            if (l <= r && cur > 0) {
                power += tokens[r--];
                cur--;
            }
        }
        
        return res;
    }
};