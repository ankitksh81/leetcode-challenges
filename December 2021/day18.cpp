/*
    Numbers at most N given digit set
    https://leetcode.com/problems/numbers-at-most-n-given-digit-set/
*/

// Solution:

class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string num = to_string(n);
        int K = num.length();
        vector<int> dp(K+1);
        dp[K] = 1;
        
        for(int i = K-1; i >= 0; i--) {
            int d = num[i] - '0';
            for(string dig: digits) {
                if(stoi(dig) < d) {
                    dp[i] += pow(digits.size(), K-i-1);
                } else if(stoi(dig) == d) {
                    dp[i] += dp[i+1];
                }
            }
        }
        
        for(int i = 1; i < K; i++) {
            dp[0] += pow(digits.size(), i);
        }
        
        return dp[0];
    }
};