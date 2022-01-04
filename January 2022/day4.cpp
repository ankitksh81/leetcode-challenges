/*
    Complement of Base 10 Integer
    https://leetcode.com/problems/complement-of-base-10-integer/
*/

// Solution: Bit Manipulation

class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0) {
            return 1;
        }
        int x = n, bit = 1;
        while(x != 0) {
            n ^= bit;
            bit <<= 1;
            x >>= 1;
        }
        
        return n;
    }
};