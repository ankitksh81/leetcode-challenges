/*
	Concatenation of Consecutive Binary Numbers
	https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers/
*/

// Solution: Bit Manipulation

class Solution {
public:
    int concatenatedBinary(int n) {
        int MOD = 1e9 + 7;
        long long res = 0;
        int ones = 0;
        
        for (int i = 1; i <= n; i++) {
            if ((i & (i - 1)) == 0) {
                ones++;
            }
            
            res = ((res << ones) + i) % MOD;
        }
        
        return res;
    }
};